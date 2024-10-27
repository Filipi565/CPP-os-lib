#define __OS_LIB_EXPORT
#include "cwalk.h"
#include <os.h>

#include <string>

#define IS_SEP(o) (o == os::SEP || o == os::ALTSEP)

using namespace std;

OS_PUBLIC int os::path::join(char *buff, size_t s, const initializer_list<const char *> &parts)
{
    try
    {
        string temp;

        for (auto part : parts)
        {
            temp += part;
            temp += os::SEP;
        }

        temp.pop_back(); // Remove trailing separator

        char new_buff[FILENAME_MAX];

        std::char_traits<char>::copy(new_buff, temp.c_str(), min(s, temp.size()));

        cwk_path_normalize(new_buff, buff, s);
    }
    catch (const exception &e)
    {
        return 1;
    }

    return 0;
}