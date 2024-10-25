#define __OS_LIB_EXPORT
#include <config.h>
#include "cwalk.h"
#include <os.h>

#include <string>

#define IS_SEP(o) (o == os::SEP || o == os::ALTSEP)

using namespace std;

OS_PUBLIC int os::path::join(char *buff, size_t s, const initializer_list<const char *> &parts)
{
    string temp;
    const char **paths = new const char*[parts.size()+1];

    if (!parts.size())
    {
        (*buff) = 0;
        return 0;
    }

    auto _first = (*parts.begin());

    char start = 0;

    bool _need_cwd = (
        ( _first[0] == '.' && IS_SEP(_first[1]) ) ||
        ( _first[0] == '.' && _first[1] == '.' && IS_SEP(_first[2]) )
    );

    if (_need_cwd)
    {
        char buffer[FILENAME_MAX];
        os::getcwd(buffer, FILENAME_MAX);

        temp = buffer;
        temp += os::SEP;
        temp += _first;

        start = 1;
        paths[0] = temp.c_str();
    }

    for (size_t i = start; i < parts.size(); i++)
    {
        paths[i] = (*parts.begin()) + i;
    }

    paths[parts.size()] = nullptr;

    cwk_path_join_multiple(paths, buff, s);

    delete[] paths;

    return 0;
}