#ifndef _OS_H_
#define _OS_H_

#include <sys/types.h>
#include <sys/stat.h>

#define __need_size_t
#include <stddef.h>

#include <initializer_list>

#define OS_PUBLIC

namespace os
{
    namespace path
    {
        OS_PUBLIC int join(char *buffer, size_t buffer_size, const std::initializer_list<const char *> &);
        OS_PUBLIC bool exists(const char *path, bool follow_symlinks = true);
        OS_PUBLIC bool is_dir(const char *path, bool follow_symlinks = true);
        OS_PUBLIC bool is_file(const char *path, bool follow_symlinks = true);
        OS_PUBLIC bool is_symlink(const char *path);
    }

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