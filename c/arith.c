#include <stdio.h>

int main()
{
    int a = 4, b = 2, c;

    c = a + b;
    printf("addition operator a + b = %d\n", c);

    c = a - b;
    printf("subtraction operator a - b = %d\n", c);

    c  = a / b;
    printf("division operator a / b = %d\n", c);

    c = a % b;
    printf("modulo operator a %% b = %d\n", c);

    c = a * b;
    printf("multiply operator a * b = %d\n", c);

    return 0;
}

