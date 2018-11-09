#include <stdio.h>

int main()
{
    int array[10] = {1, 42,411, 42141, 5, 2, 2, 52};
    void *p = array;


    printf("%p %p\n", p, p + 1);
}

