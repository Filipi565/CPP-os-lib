#ifndef _OS_H_
#define _OS_H_

#include <sys/types.h>
#include <sys/stat.h>

#include <config.h>

#define __need_size_t
#include <stddef.h>

namespace os
{
    #ifdef _WIN32
    const char SEP = '\\';
    #else
    const char SEP = '/';
    #endif // _WIN32

    const char ALTSEP = '/'; // Always '/'

    OS_PUBLIC int getcwd(char *buffer, size_t buffer_size);
    OS_PUBLIC int chdir(const char *path);
}

#endif