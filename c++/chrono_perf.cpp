/**
 * Written by Devendra Naga (devendra.aaru@gmail.com)
 * 
 * License Apache
 */
#include <iostream>
#include <chrono>

int main()
{
    int i;

    std::chrono::time_point<std::chrono::steady_clock> cur;

    cur = std::chrono::steady_clock::now();

    for (i = 0; i < 10000000; i++) {
    }

    std::chrono::time_point<std::chrono::steady_clock> now;

    now = std::chrono::steady_clock::now();

    std::chrono::duration<double> delta = now - cur;

    std::cout << " time took " << delta.count() << " secs" << std::endl;
}
