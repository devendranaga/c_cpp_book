#include <stdio.h>

int main()
{
    int array[10] = {441, 84, 8, 41};
    void *p = array;

    printf("p %p\n", p);

    p ++;

    printf("p %p\n", p);
}

