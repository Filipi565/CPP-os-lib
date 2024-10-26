#ifndef _OS_H_
#define _OS_H_

#define OS_PUBLIC

#undef __OS_LIB_EXPORT
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

#include <sys/types.h>
#include <sys/stat.h>

#define __need_size_t
#include <stddef.h>

#include <initializer_list>

namespace os
{
    namespace path
    {
        OS_PUBLIC int join(char *buffer, size_t maxlength, const std::initializer_list<const char *> &);
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

    OS_PUBLIC int getcwd(char *buffer, size_t maxlength);
    OS_PUBLIC int chdir(const char *path);
}

#endif