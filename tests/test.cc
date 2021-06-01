#include <iostream>
#include <thread>
#include "../MSF/log.h"
#include "../MSF/util.h"

int main (int argc,char** argv) {
	MSF::Logger::ptr logger(new MSF::Logger);
	logger->addAppender(MSF::LogAppender::ptr(new MSF::StdoutLogAppender));

	MSF::FileLogAppender::ptr file_appender(new MSF::FileLogAppender("./log.txt"));
	MSF::LogFormatter::ptr fmt(new MSF::LogFormatter("%d%T%p%T%m%n"));
	file_appender->setFormatter(fmt);
	file_appender->setLevel(MSF::LogLevel::ERROR);
	logger->addAppender(file_appender);

//	MSF::LogEvent::ptr event (new MSF::LogEvent(__FILE__, __LINE__, 0, MSF::GetThreadId(), MSF::GetFiberId(), time(0)));
//	event->getSS() << "hello MSF log";
//	logger->log(MSF::LogLevel::DEBUG, event);
	std::cout << "hello MSF log" << std::endl;

	MSF_LOG_INFO(logger) << "test macro";
	MSF_LOG_ERROR(logger) << "test macro error";
	
	MSF_LOG_FMT_ERROR(logger, "test macro fmt error %s", "aa");

	auto l = MSF::LoggerMgr::GetInstance()->getLogger("xx");
	MSF_LOG_INFO(l) << "xxx";
	return 0;
}

