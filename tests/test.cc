#include <iostream>
#include "../MSF/log.h"

int main (int argc,char** argv) {
	MSF::Logger::ptr logger(new MSF::Logger);
	logger->addAppender(MSF::LogAppender::ptr(new MSF::StdoutLogAppender));

	MSF::LogEvent::ptr event (new MSF::LogEvent(__FILE__, __LINE__, 0, 1, 2, time(0)));

	logger->log(MSF::LogLevel::DEBUG, event);
	std::cout << "hello MSF log" << std::endl;

	return 0;
}

