#define __OS_LIB_EXPORT
#include <stdexcept>
#include <os.h>

#ifdef _WIN32
#include "windirent.h"
#else
#include <dirent.h>
#endif

#include <vector>
#include <string>

using namespace std;

namespace os
{
    OS_PUBLIC vector<string> listdir(const char *path)
    {
        if (!os::path::exists(path))
        {
            throw invalid_argument("Path does not exist: " + string(path));
        }

        if (!os::path::is_dir(path))
        {
            throw invalid_argument("Path is not a directory: " + string(path));
        }

        vector<string> result;

        dirent **namelist;

        int n = scandir(path, &namelist, nullptr, alphasort);
        if (n < 0)
        {
            throw runtime_error("Error scanning directory: " + string(path));
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (namelist[i]->d_name == string(".") || namelist[i]->d_name == string(".."))
                {
                    free(namelist[i]);
                    continue;
                }

                result.push_back(namelist[i]->d_name);
                free(namelist[i]);
            }
            free(namelist);
        }

        result.shrink_to_fit();
        return result;
    }
}