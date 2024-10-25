#ifndef _OS_NAMES_H_
#define _OS_NAMES_H_

#ifdef _WIN32
#include <direct.h>
#define NAME(n) _ ## n
#else
#include <unistd.h>
#define NAME(n) n
#endif

#endif