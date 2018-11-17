#include <iostream>
#include <thread>

void start_func(int *n)
{
    std::cout << "thread execute.. " << std::endl;

    *n = 10;
}

int main()
{
    int n = 0;

    std::thread t(start_func, &n);

    std::cout << "thread id " << t.get_id() << std::endl;

    t.join();

    std::cout <<" n = " << n << std::endl;

    return 0;
}

