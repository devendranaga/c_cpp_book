#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **dptr;
    int i;

    dptr = malloc(10 * sizeof(int *));
    if (!dptr) {
        return -1;
    }

    for (i = 0; i < 10; i ++) {
        dptr[i] = malloc(sizeof(int));
        if (!dptr[i]) {
            return -1;
        }

        *(dptr[i]) = i;
    }

    for (i = 0; i < 10; i ++) {
        printf("dptr [%d] = %d\n", i, *dptr[i]);
        free(dptr[i]);
    }

    free(dptr);

    return 0;
}

