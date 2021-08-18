#include "MSF/MSF.h"
#include <assert.h>

MSF::Logger::ptr g_logger = MSF_LOG_ROOT();

void test_assert() {
	MSF_LOG_INFO(g_logger) << MSF::BacktraceToString(10, 2, "^_^==");
	MSF_ASSERT2(0 == 1, "abcdefhg");
}
int main(int argc, char** argv) {
	test_assert();
	return 0;
}
