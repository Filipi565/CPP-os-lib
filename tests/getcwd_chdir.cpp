#include <libos/os.h>
#include <iostream>

int main(void)
{
    char buffer[4096];
    os::getcwd(buffer, 4096);

    std::cout << "Current working directory: " << buffer << '\n';

    os::chdir("..");
    os::getcwd(buffer, 4096);

    std::cout << "Changed working directory: " << buffer << '\n';
    
    return 0;
}