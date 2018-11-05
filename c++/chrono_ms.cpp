/**
 * Written by Devendra Naga (devendra.aaru@gmail.com)
 * 
 * License Apache
 */
#include <iostream>
#include <chrono>

// for std::chrono::milliseconds:: and the nametyping
using namespace std::chrono_literals;

int main()
{
    std::chrono::milliseconds ms = 1s;

    std::cout << "number of milliseconds " << ms.count() << std::endl;
}
