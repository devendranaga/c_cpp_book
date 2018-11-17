#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *i;

    i = malloc(sizeof(int));
    if (!i) {
        return -1;
    }

    *i = 10;

    printf("value i %d\n", *i);

    free(i);
}

