#include <iostream>
#include <thread>

int main()
{
    std::cout  << "concurrent threads " << std::thread::hardware_concurrency() << std::endl;
}

