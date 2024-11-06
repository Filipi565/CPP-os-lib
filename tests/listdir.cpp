#include <libos/os.h>
#include <iostream>

int main(int, const char *argv[])
{
    char buffer[4096];
    os::path::join(buffer, 4096, {argv[0], "..", ".."});

    auto items = os::listdir(buffer);

    for (auto &item : items)
    {
        std::cout << item << '\n';
    }
    
    return 0;
}