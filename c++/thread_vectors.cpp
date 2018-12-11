#include <iostream>
#include <vector>
#include <thread>
#include <unistd.h>
#include <mutex>

std::mutex lock;

void thread_routine(int i)
{
    while (1) {
        lock.lock();
        std::cout << "-------------" <<std::endl;
        std::cout <<" thread " << i << "  tid: " << std::this_thread::get_id() << std::endl;
        std::cout << "-------------" <<std::endl;
        lock.unlock();

        sleep(1);
    }
}

int main()
{
    std::vector<std::thread *> thread_vec;
    uint32_t data[4];
    uint32_t i;

    lock.lock();

    for (i = 0; i < 4; i ++) {
        data[i] = i;
        std::thread *obj = new std::thread(&thread_routine, data[i]);

        thread_vec.push_back(obj);
    }

    lock.unlock();

    std::vector<std::thread *>::iterator it;

    for (it = thread_vec.begin(); it != thread_vec.end(); it ++) {
        std::thread *id = *it;

        id->join();
    }
}

