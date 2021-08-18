#ifndef __MSF_MACRO_H__
#define __MSF_MACRO_H__

#include <string.h>
#include <assert.h>
#include "log.h"
#include "util.h"

#if defined __GNUC__ || defined __llvm__
/// LIKCLY 宏的封装, 告诉编译器优化,条件大概率成立
#   define MSF_LIKELY(x)       __builtin_expect(!!(x), 1)
/// LIKCLY 宏的封装, 告诉编译器优化,条件大概率不成立
#   define MSF_UNLIKELY(x)     __builtin_expect(!!(x), 0)
#else
#   define MSF_LIKELY(x)      (x)
#   define MSF_UNLIKELY(x)      (x)
#endif

/// 断言宏封装
#define MSF_ASSERT(x) \
    if(MSF_UNLIKELY(!(x))) { \
        MSF_LOG_ERROR(MSF_LOG_ROOT()) << "ASSERTION: " #x \
            << "\nbacktrace:\n" \
            << MSF::BacktraceToString(100, 2, "    "); \
        assert(x); \
    }

/// 断言宏封装
#define MSF_ASSERT2(x, w) \
    if(MSF_UNLIKELY(!(x))) { \
        MSF_LOG_ERROR(MSF_LOG_ROOT()) << "ASSERTION: " #x \
            << "\n" << w \
            << "\nbacktrace:\n" \
            << MSF::BacktraceToString(100, 2, "    "); \
        assert(x); \
    }


#endif
