#include <iostream>
#include <thread>
#include <chrono>

class thread_class {
    private:
        std::thread *ptr;
        void thread_call()
        {
            while (1) {
                std::cout << "thread ..\n";

                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
    public:
        thread_class()
        {
            ptr = new std::thread(&thread_class::thread_call, this);

        }

        void thread_join()
        {
            ptr->join();
        }
};

int main(int argc, char **argv)
{
    thread_class t;

    t.thread_join();
}

