#include <stdio.h>

int main()
{
    enum {
        APPLES = 1,
        ORANGES = 2,
        MANGO = 3,
        LITCHI = 4,
    } fruits;

    printf("%ld\n", sizeof(fruits));
}

