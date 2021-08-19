#include "scheduler.h"
#include "macro.h"
#include "log.h"

namespace MSF {

static MSF::Logger::ptr g_logger = MSF_LOG_NAME("system");

static thread_local Scheduler* t_scheduler = nullptr;
static thread_local Fiber* t_fiber = nullptr;

Scheduler::Scheduler(size_t threads, bool use_caller, const std::string& name)
	:m_name(name) {
	MSF_ASSERT(threads > 0);

	if(use_caller) {
		MSF::Fiber::GetThis();
		--threads;

		MSF_ASSERT(GetThis() == nullptr);
		t_scheduler = this;

		m_rootFiber.reset(new Fiber(std::bind(&Scheduler::run, this), 0, true));
		MSF::Thread::SetName(m_name);

		t_fiber = m_rootFiber.get();
		m_rootThread = MSF::GetThreadId();
		m_threadIds.push_back(m_rootThread);
	}
	else {
		m_rootThread = -1;
	}
	m_threadCount = threads;
}

Scheduler::~Scheduler() {
	MSF_ASSERT(m_stopping);
	if(GetThis() == this) {
		t_scheduler = nullptr;
	}
}

Scheduler* Scheduler::GetThis() {
	return t_scheduler;
}

Fiber* Scheduler::GetMainFiber() {
	return t_fiber;
}

void Scheduler::start() {
	MutexType::Lock lock(m_mutex);
	if(!m_stopping) {
		return;
	}
	m_stopping = false;
	MSF_ASSERT(m_threads.empty());

	m_threads.resize(m_threadCount);
	for(size_t i = 0; i < m_threadCount; ++i) {
		m_threads[i].reset(new Thread(std::bind(&Scheduler::run, this)
					, m_name + "_" + std::to_string(i)));
		m_threadIds.push_back(m_threads[i]->getId());
	}
	lock.unlock();

	/*if(m_rootFiber) {
		m_rootFiber->call();
		//m_rootFiber->swapIn();
		MSF_LOG_INFO(g_logger) << "call out" << m_rootFiber->getState();
	}*/
}

void Scheduler::stop() {
	m_autoStop = true;
	if(m_rootFiber 
			&& m_threadCount == 0 
			&& (m_rootFiber->getState() == Fiber::TERM
				|| m_rootFiber->getState() == Fiber::INIT)) {
		MSF_LOG_INFO(g_logger) << this << " stopped";
		m_stopping = true;
		
		if(stopping()) {
			return;
		}
	}

	//bool exit_on_this_fiber = false;
	if(m_rootThread != -1) {	//用了use_caller时，stop要在创建的线程里执行
		MSF_ASSERT(GetThis() == this);
	}
	else {
		MSF_ASSERT(GetThis() != this);
	}

	m_stopping = true;
	for(size_t i = 0; i < m_threadCount; ++i) {
		tickle();
	}

	if(m_rootFiber) {
		tickle();
	}

	if(m_rootFiber) {
		if(!stopping()) {
			m_rootFiber->call();
		}
	}
	
	std::vector<Thread::ptr> thrs;
    {
        MutexType::Lock lock(m_mutex);
        thrs.swap(m_threads);
    }

    for(auto& i : thrs) {
        i->join();
    }

	//if(exit_on_this_fiber) {

	//}
}

void Scheduler::setThis() {
	t_scheduler = this;
}

void Scheduler::run() {
	MSF_LOG_DEBUG(g_logger) << m_name << "run"; 
	setThis();
	if(MSF::GetThreadId() != m_rootThread) {
		t_fiber = Fiber::GetThis().get();
	}

	Fiber::ptr idle_fiber(new Fiber(std::bind(&Scheduler::idle, this)));
	Fiber::ptr cb_fiber;

	FiberAndThread ft;
	while(true) {
		ft.reset();
		bool tickle_me = false;
		bool is_active = false;
		{ //从消息队列中取出要执行的消息
			MutexType::Lock lock(m_mutex);
			auto it = m_fibers.begin();
			while(it != m_fibers.end()) {
				if(it->thread != -1 && it->thread != MSF::GetThreadId()) { //自己不能处理，交给别的线程
					++it;
					tickle_me = true;
					continue;
				}

				MSF_ASSERT(it->fiber || it->cb);
				if(it->fiber && it->fiber->getState() == Fiber::EXEC) {
					++it;
					continue;
				}

				ft = *it;
				m_fibers.erase(it++);
				++m_activeThreadCount;
				is_active = true;
				break;
			}
			tickle_me |= it != m_fibers.end();
		}

		if(tickle_me) {
			tickle();
		}

		if(ft.fiber && (ft.fiber->getState() != Fiber::TERM
						&& ft.fiber->getState() != Fiber::EXCEPT)) {
			ft.fiber->swapIn();
			--m_activeThreadCount;

			if(ft.fiber->getState() == Fiber::READY) {
				scheduler(ft.fiber);
			}
			else if(ft.fiber->getState() != Fiber::TERM
					&& ft.fiber->getState() != Fiber::EXCEPT) {
				ft.fiber->m_state = Fiber::HOLD;
			}
			ft.reset();
		}
		else if(ft.cb) {
			if(cb_fiber) {
				cb_fiber->reset(ft.cb);
			}
			else {
				cb_fiber.reset(new Fiber(ft.cb));
			}
			ft.reset();
			cb_fiber->swapIn();
			--m_activeThreadCount;
			if(cb_fiber->getState() == Fiber::READY) {
				scheduler(cb_fiber);
				cb_fiber.reset();
			}
			else if(cb_fiber->getState() == Fiber::EXCEPT
					|| cb_fiber->getState() == Fiber::TERM) {
				cb_fiber->reset(nullptr);
			}
			else { //if(cb_fiber->getState() != Fiber::TERM) {
				cb_fiber->m_state = Fiber::HOLD;
				cb_fiber.reset();
			}
		}
		else {//没有任务执行idel
			if(is_active) {
				--m_activeThreadCount;
				continue;
			}
			if(idle_fiber->getState() == Fiber::TERM) {
				MSF_LOG_INFO(g_logger) << "idle fiber term";
				break;
			}

			++m_idleThreadCount;
			idle_fiber->swapIn();
			--m_idleThreadCount;
			if(idle_fiber->getState() != Fiber::TERM
					&& idle_fiber->m_state != Fiber::EXCEPT) {
				idle_fiber->m_state = Fiber::HOLD;
			}
		}
	}
}

void Scheduler::tickle() {
	MSF_LOG_INFO(g_logger) << "tickle";
}

bool Scheduler::stopping() {
	MutexType::Lock lock(m_mutex);
	return m_autoStop && m_stopping 
		&& m_fibers.empty() && m_activeThreadCount == 0;
}

void Scheduler::idle() {
	MSF_LOG_INFO(g_logger) << "idle";
	while(!stopping()) {
		MSF::Fiber::YieldToHold();
	}
}

}

