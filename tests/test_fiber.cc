#include "MSF/MSF.h"

MSF::Logger::ptr g_logger = MSF_LOG_ROOT();

void run_in_fiber() {
	MSF_LOG_INFO(g_logger) << "run_in_fiber begin";
	MSF::Fiber::YieldToHold();
	MSF_LOG_INFO(g_logger) << "run_in_fiber end";
	MSF::Fiber::YieldToHold();
}

void test_fiber() {
	MSF_LOG_INFO(g_logger) << "main begin -1";
	{
		MSF::Fiber::GetThis();
		MSF_LOG_INFO(g_logger) << "main begin";
		MSF::Fiber::ptr fiber(new MSF::Fiber(run_in_fiber));
		fiber->swapIn();
		MSF_LOG_INFO(g_logger) << "main after swapIn";
		fiber->swapIn();
		MSF_LOG_INFO(g_logger) << "main after end"; 
		fiber->swapIn();
	}
	MSF_LOG_INFO(g_logger) << "main after end2";
}

int main(int argc, char** argv) {
	MSF::Thread::SetName("main");
	
	std::vector<MSF::Thread::ptr> thrs;
	for(int i = 0; i < 3; ++i) {
		thrs.push_back(MSF::Thread::ptr(
					new MSF::Thread(&test_fiber, "name_" + std::to_string(i))));
	}
	for(auto i : thrs) {
		i->join();
	}
	return 0;
}
