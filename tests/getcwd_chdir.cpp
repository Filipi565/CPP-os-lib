#include <libos/os.h>
#include <iostream>

int main(void)
{
    char buffer[FILENAME_MAX];
    os::getcwd(buffer, FILENAME_MAX);

    std::cout << "Current working directory: " << buffer << '\n';

    os::chdir("..");
    os::getcwd(buffer, FILENAME_MAX);

    std::cout << "Changed working directory: " << buffer << '\n';
    
    return 0;
}