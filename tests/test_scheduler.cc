#include "MSF/MSF.h"

static MSF::Logger::ptr g_logger = MSF_LOG_ROOT();

int main(int argc, char** argv) {
	MSF::Scheduler sc;
	sc.start();
	sc.stop();
	return 0;
}
