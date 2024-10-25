#define __OS_LIB_EXPORT
#include <os.h>

#include "names.h"

#define STAT NAME(stat)
#define LSTAT NAME(lstat)

namespace os::path
{
    OS_PUBLIC bool exists(const char *path, bool follow_symlinks)
    {
        struct STAT info;
        int result;

        if (follow_symlinks)
        {
            result = STAT(path, &info);
        }
        else
        {
            result = LSTAT(path, &info);
        }

        return (result == 0);
    }

    OS_PUBLIC bool is_dir(const char *path, bool follow_symlinks)
    {
        struct STAT info;
        int result;

        if (follow_symlinks)
        {
            result = STAT(path, &info);
        }
        else
        {
            result = LSTAT(path, &info);
        }

        if (result != 0)
        {
            return false;
        }

        return S_ISDIR(info.st_mode);
    }

    OS_PUBLIC bool is_file(const char *path, bool follow_symlinks)
    {
        struct STAT info;
        int result;

        if (follow_symlinks)
        {
            result = STAT(path, &info);
        }
        else
        {
            result = LSTAT(path, &info);
        }

        if (result != 0)
        {
            return false;
        }

        return S_ISREG(info.st_mode);
    }

    OS_PUBLIC bool is_symlink(const char *path)
    {
        struct STAT info;
        int result = LSTAT(path, &info);

        if (result != 0)
        {
            return false;
        }

        return S_ISLNK(info.st_mode);
    }
}