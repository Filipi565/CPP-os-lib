#include <libos/os.h>
#include <iostream>

int main(int, const char *argv[])
{
    char *buffer = new char[4096];

    os::path::join(buffer, 4096, {argv[0], ".."});

    std::cout << "File: " << buffer << '\n';
    std::cout << "Exists: " << os::path::exists(buffer) << '\n';
    std::cout << "Is dir: " << os::path::is_dir(buffer) << '\n';
    std::cout << "Is file: " << os::path::is_file(buffer) << '\n';

    delete[] buffer;
    
    return 0;
}