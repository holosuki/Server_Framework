#ifndef __MSF__FIBER_H__
#define __MSF__FIBER_H__

#include <memory>
#include <functional>
#include <ucontext.h>
#include "thread.h"

namespace MSF {

class Scheduler;

class Fiber : public std::enable_shared_from_this<Fiber> {
friend class Scheduler;
public:
	typedef std::shared_ptr<Fiber> ptr;

	enum State {
		INIT,//初始化
		HOLD,//保持
		EXEC,//执行
		TERM,//终止
		READY,//准备
		EXCEPT//出错
	};
private:
	Fiber();//不让创建默认对象;

public:
	Fiber(std::function<void()> cb, size_t stacksize = 0, bool use_caller = false);
	~Fiber();

	//重置协程函数，并重置状态，重新利用已分配的空间
	//INIT, TERM
	void reset(std::function<void()> cb);
	//切换到当前协程进行
	void swapIn();
	//切换到后台执行
	void swapOut();

	void call();
	void back();

	uint64_t getId() const { return m_id;}
	State getState() const { return m_state;}
public:
	//设置当前线程的运行协程
	static void SetThis(Fiber* f);
	//返回当前协程
	static Fiber::ptr GetThis();
	//协程切换到后台，并且设置为Ready状态
	static void YieldToReady();
	//协程切换到后台，并且设置为Hold状态
	static void YieldToHold();
	//总协程数
	static uint64_t TotalFibers();

	static void MainFunc();
	static void CallerMainFunc();
	static uint64_t GetFiberId();
private:
	uint64_t m_id = 0;
	uint64_t m_stacksize = 0;
	State m_state = INIT;

	ucontext_t m_ctx;
	void* m_stack = nullptr;

	std::function<void()> m_cb;
};

}

#endif
