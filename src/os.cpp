#define __OS_LIB_EXPORT
#include <os.h>

#include "names.h"

#define GETCWD NAME(getcwd)
#define CHDIR NAME(chdir)

namespace os
{
    OS_PUBLIC int getcwd(char *buff, size_t s)
    {
        return (::GETCWD(buff, s) == NULL);
    }

    OS_PUBLIC int chdir(const char *path)
    {
        return ::CHDIR(path);
    }
}