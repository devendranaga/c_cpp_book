#include <stdio.h>

int main()
{
    int i = 4;
    int *p = &i;

    *p = 2;

    printf("%d %d\n", i, *p);
}

