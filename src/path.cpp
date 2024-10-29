#define __OS_LIB_EXPORT
#include <os.h>

#include "names.h"

#define STAT NAME(stat)
#define LSTAT NAME(lstat)

namespace os::path
{
    OS_PUBLIC bool exists(const char *path)
    {
        struct STAT info;

        return (STAT(path, &info) == 0);
    }

    OS_PUBLIC bool is_dir(const char *path)
    {
        struct STAT info;
        
        if (STAT(path, &info) != 0)
        {
            return false;
        }

        return S_ISDIR(info.st_mode);
    }

    OS_PUBLIC bool is_file(const char *path)
    {
        struct STAT info;
        
        if (STAT(path, &info) != 0)
        {
            return false;
        }

        return S_ISREG(info.st_mode);
    }
}