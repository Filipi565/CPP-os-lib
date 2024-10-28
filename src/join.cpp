#define __OS_LIB_EXPORT
#include "cwalk.h"
#include <os.h>

#include <string>

#define IS_SEP(o) (o == os::SEP || o == os::ALTSEP)

#define OS_PATH_MAX ((std::size_t)4096)

using namespace std;

OS_PUBLIC int os::path::join(char *buff, size_t s, const initializer_list<const char *> &parts)
{
    try
    {
        string temp;

        auto first = (*parts.begin());

        bool need_cwd = (
            first[0] == '.' && (IS_SEP(first[1]) ||
            first[1] == '.' && IS_SEP(first[2]))
        );

        if (need_cwd)
        {
            char cwd[OS_PATH_MAX];
            os::getcwd(cwd, OS_PATH_MAX);

            temp = cwd;
            temp += os::SEP;
        }

        for (auto part : parts)
        {
            temp += part;
            temp += os::SEP;
        }

        temp.pop_back(); // Remove trailing separator

        char new_buff[OS_PATH_MAX];

        std::char_traits<char>::copy(new_buff, temp.c_str(), min(OS_PATH_MAX, temp.size()));

        cwk_path_normalize(new_buff, buff, s);
    }
    catch (const exception &)
    {
        return 1;
    }

    return 0;
}