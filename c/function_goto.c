#include <stdio.h>

int main()
{
    int f()
    {
        goto jmp;
    }

jmp:
    printf("hello call f\n");

    f();

    return 0;
}

