#include <iostream>
#include <thread>
#include <chrono>

void thread_callback(void *null)
{
    while (1) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "thread callback triggered" << std::endl;
    }
}

int main()
{
    std::thread *new_thr;

    new_thr = new std::thread(thread_callback, nullptr);
    if (new_thr == nullptr) {
        std::cout << "failed to create new_thread" << std::endl;
        return -1;
    }

    // wait for the thread
    new_thr->join();

    delete new_thr;
}

