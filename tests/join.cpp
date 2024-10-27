#include <libos/os.h>
#include <iostream>

int main(int, const char *argv[])
{
    char buffer[FILENAME_MAX];

    os::path::join(buffer, FILENAME_MAX, {argv[0], ".."});

    std::cout << "Joined path: " << buffer << '\n';
    
    return 0;
}