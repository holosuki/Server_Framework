#include "MSF/MSF.h"
#include "MSF/iomanager.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <sys/epoll.h>

MSF::Logger::ptr g_logger = MSF_LOG_ROOT();

int sock = 0;

void test_fiber() {
    MSF_LOG_INFO(g_logger) << "test_fiber sock=" << sock;

    //sleep(3);

    //close(sock);
    //MSF::IOManager::GetThis()->cancelAll(sock);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    fcntl(sock, F_SETFL, O_NONBLOCK);

    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    inet_pton(AF_INET, "180.101.49.12", &addr.sin_addr.s_addr);

    if(!connect(sock, (const sockaddr*)&addr, sizeof(addr))) {
    } else if(errno == EINPROGRESS) {
        MSF_LOG_INFO(g_logger) << "add event errno=" << errno << " " << strerror(errno);
        MSF::IOManager::GetThis()->addEvent(sock, MSF::IOManager::READ, [](){
            MSF_LOG_INFO(g_logger) << "read callback";
        });
        MSF::IOManager::GetThis()->addEvent(sock, MSF::IOManager::WRITE, [](){
            MSF_LOG_INFO(g_logger) << "write callback";
            //close(sock);
            MSF::IOManager::GetThis()->cancelEvent(sock, MSF::IOManager::READ);
            close(sock);
        });
    } else {
        MSF_LOG_INFO(g_logger) << "else " << errno << " " << strerror(errno);
    }

}

void test1() {
    std::cout << "EPOLLIN=" << EPOLLIN
              << " EPOLLOUT=" << EPOLLOUT << std::endl;
    MSF::IOManager iom(2, false);
    iom.scheduler(&test_fiber);
}

/*MSF::Timer::ptr s_timer;
void test_timer() {
    MSF::IOManager iom(2);
    s_timer = iom.addTimer(1000, [](){
        static int i = 0;
        MSF_LOG_INFO(g_logger) << "hello timer i=" << i;
        if(++i == 3) {
            s_timer->reset(2000, true);
            //s_timer->cancel();
        }
    }, true);
}*/

int main(int argc, char** argv) {
    test1();
    //test_timer();
    return 0;
}

