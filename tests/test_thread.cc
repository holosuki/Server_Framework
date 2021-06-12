#include "../MSF/MSF.h"
#include <unistd.h>

MSF::Logger::ptr g_logger = MSF_LOG_ROOT();

void fun1() {
    MSF_LOG_INFO(g_logger) << "name: " << MSF::Thread::GetName()
                             << " this.name: " << MSF::Thread::GetThis()->getName()
                             << " id: " << MSF::GetThreadId()
                             << " this.id: " << MSF::Thread::GetThis()->getId();

}

void fun2() {
    while(true) {
        MSF_LOG_INFO(g_logger) << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    }
}

void fun3() {
    while(true) {
        MSF_LOG_INFO(g_logger) << "========================================";
    }
}

int main(int argc, char** argv) {
    MSF_LOG_INFO(g_logger) << "thread test begin";

    std::vector<MSF::Thread::ptr> thrs;
    for(int i = 0; i < 5; ++i) {
        MSF::Thread::ptr thr(new MSF::Thread(&fun1, "name_" + std::to_string(i)));
        thrs.push_back(thr);
    }

    for(int i = 0; i < 5; ++i) {
        thrs[i]->join();
    }
    MSF_LOG_INFO(g_logger) << "thread test end";

    return 0;
}

