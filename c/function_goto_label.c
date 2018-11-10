#include <stdio.h>

int main()
{
    __label__ jmp;

    int f()
    {
        printf("f called\n");
        goto jmp;
    }

    printf("function call ..\n");

jmp:
    f();
}

