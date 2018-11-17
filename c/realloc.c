#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int *new_ptr;

    ptr = calloc(1, sizeof(int));
    if (!ptr) {
        return -1;
    }

    *ptr = 4;

    new_ptr = realloc(ptr, sizeof(int) * 4);
    if (!new_ptr) {
        return -1;
    }

    int i;

    for (i = 0; i < 4; i ++) {
        new_ptr[i] = i;
    }

    for (i = 0; i < 4; i ++) {
        printf("%d\n", new_ptr[i]);
    }

    return 0;
}

