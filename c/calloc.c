#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int *a;

    a = calloc(1, sizeof(int));
    if (!a) {
        return -1;
    }

    *a = 10;

    printf("a is %d\n", *a);
    return 0;
}

