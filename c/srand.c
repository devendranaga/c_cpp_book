#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
    int rand_;
    struct timeval tv_;

    gettimeofday(&tv_, 0);

    srand(tv_.tv_usec);

    rand_ = rand();

    printf("random number %d\n", rand_);
}

