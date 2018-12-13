#include <iostream>
#include <vector>
#include <sys/time.h>

int main()
{
    std::vector<int> list;

    struct timeval start, stop;
    struct timeval delta;

    gettimeofday(&start, 0);

    //list.reserve(1000);

    int i;

    for (i = 0; i < 1000; i ++) {
        list.push_back(i);
    }

    gettimeofday(&stop, 0);

    timersub(&stop, &start, &delta);

    std::cout << delta.tv_sec << " " << delta.tv_usec << std::endl;

    return 0;
}

