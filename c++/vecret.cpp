#include <iostream>
#include <vector>
#include <sys/time.h>

std::vector<int> *listOfInt()
{
    std::vector<int> *v = new std::vector<int>;
    int i;

    for (i = 0; i < 1000; i ++) {
        v->push_back(i);
    }

    return v;
}

std::vector<int> listOfInts()
{
    std::vector<int> v;
    int i;

    for (i = 0; i < 1000; i ++) {
        v.push_back(i);
    }

    return v;
}

int main()
{
    std::vector<int> i1;
    std::vector<int> *i;
    struct timeval start, stop;
    struct timeval delta;

    gettimeofday(&start, 0);
    i1 = listOfInts();
    gettimeofday(&stop, 0);

    timersub(&stop, &start, &delta);

    std::cout << delta.tv_sec << " " << delta.tv_usec << std::endl;

    gettimeofday(&start, 0);
    i = listOfInt();
    gettimeofday(&stop, 0);

    timersub(&stop, &start, &delta);

    std::cout << delta.tv_sec << " " << delta.tv_usec << std::endl;

    std::vector<int>::const_iterator it;
    //for (it = i->begin(); it != i->end(); it ++) {
    //    std::cout << *it << std::endl;
    //}

    delete i;
    return 0;
}

