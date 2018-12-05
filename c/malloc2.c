#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *t;

    t = malloc(0);
    if (!t) {
        return -1;
    }

    printf("t %p\n", t);

    free(t);
}

