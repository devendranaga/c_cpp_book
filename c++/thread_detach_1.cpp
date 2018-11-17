#include <iostream>
#include <thread>
#include <chrono>

void thread_f(int *n)
{
    while (1) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        (*n) ++;

        std::cout <<" executing thread.. " << std::endl;
    }
}

int main()
{
    int n = 0;

    std::thread t(thread_f, &n);

    t.detach();

    std::cout <<" try joining detach thread.. " << std::endl;

    if (t.joinable()) {
        t.join();
    } else {

        std::cout << "thread isn't joinable.. " << std::endl;

        // so wait for the thraed to finish the task..
        //
        while (1) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

