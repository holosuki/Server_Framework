#include "MSF/MSF.h"

static MSF::Logger::ptr g_logger = MSF_LOG_ROOT();

void test_fiber() {
    static int s_count = 5;
    MSF_LOG_INFO(g_logger) << "test in fiber s_count=" << s_count;

    sleep(1);
    if(--s_count >= 0) {
        MSF::Scheduler::GetThis()->scheduler(&test_fiber, MSF::GetThreadId());
    }
}

int main(int argc, char** argv) {
    MSF_LOG_INFO(g_logger) << "main";
    MSF::Scheduler sc(3, false, "test");
    sc.start();
	sleep(2);
    MSF_LOG_INFO(g_logger) << "schedule";
	sc.scheduler(&test_fiber);
    sc.stop();
    MSF_LOG_INFO(g_logger) << "over";
    return 0;
}

