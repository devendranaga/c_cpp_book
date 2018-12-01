#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *list;
    int i;
    int ret;

    list = malloc(10 * sizeof(int));
    if (!list) {
        return -1;
    }

    for (i = 0; i < 10; i ++) {
        list[i] = i;
    }

    for (i = 0; i < 10; i ++) {
        fprintf(stderr, "list [%d] = %d\n", i, list[i]);
    }

    free(list);

    return 0;
}

