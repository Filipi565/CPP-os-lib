#ifndef _OS_CONFIG_H_
#define _OS_CONFIG_H_

#include <__defs.h>

#ifdef _WIN32
#define OS_EXPORT __declspec(dllexport)
#define OS_IMPORT __declspec(dllimport)
#elif __GNUC__ >= 4
#define OS_EXPORT __attribute__ ((visibility("default")))
#define OS_IMPORT __attribute__ ((visibility("default")))
#else
#define OS_EXPORT
#define OS_IMPORT
#endif

#if defined(_WIN32) && defined(__TINYC__)
#define __declspec(x) __attribute__((x))
#endif

#endif