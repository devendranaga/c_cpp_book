/**
 * Written by Devendra Naga (devendra.aaru@gmail.com)
 * 
 * License Apache
 */
#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

int main()
{
    auto day = 24h;
    auto secs = 60s;
    auto millisec = 100ms;

    std::cout << "seconds: " << secs.count() << "\n"
              << "hours in day: " << day.count() << "\n"
              << "miiseconds: " << millisec.count() << std::endl;
}
