#include <stdio.h>

int main()
{
    int var = 10;

    void *p = var;

    printf("size of void p is %d\n", sizeof(p));
}

