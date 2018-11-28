#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    std::thread thread_1([]{
            while (1) {
                std::this_thread::sleep_for(std::chrono::seconds(1));

                std::cout << "thread ..\n";
            }
    });

    thread_1.join();

    return 0;
}

