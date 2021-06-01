#include <iostream>
#include <thread>
#include "../MSF/log.h"
#include "../MSF/util.h"

int main (int argc,char** argv) {
	MSF::Logger::ptr logger(new MSF::Logger);
	logger->addAppender(MSF::LogAppender::ptr(new MSF::StdoutLogAppender));

//	MSF::LogEvent::ptr event (new MSF::LogEvent(__FILE__, __LINE__, 0, MSF::GetThreadId(), MSF::GetFiberId(), time(0)));
//	event->getSS() << "hello MSF log";
//	logger->log(MSF::LogLevel::DEBUG, event);
	std::cout << "hello MSF log" << std::endl;

	MSF_LOG_INFO(logger) << "test macro";
	MSF_LOG_ERROR(logger) << "test macro error";
//	MSF_LOG_WARN(logger) << "test macro";
//	MSF_LOG_FATAL(logger) << "test macro";
//	MSF_LOG_DEBUG(logger) << "test macro";
	return 0;
}

