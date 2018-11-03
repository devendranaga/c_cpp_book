/**
 * @brief - largest number in array
 *
 * Author: Dev Naga <devendra.aaru@gmail.com>
 *
 * Apache LICENCE
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int *array;
    int var;
    int i;

    if (argc != 2) {
        fprintf(stderr, "<%s> number-of-elements\n", argv[0]);
        return -1;
    }

    var = atoi(argv[1]);

    array = calloc(1, sizeof(int) * var);
    if (!array) {
        return -1;
    }

    for (i = 0; i < var; i ++) {
        array[i] = rand();
    }

    int larger = 0;

    for (i = 0; i < var; i ++) {
        printf("array[%d] %d\n", i, array[i]);
        if (array[i] > larger) {
            larger = array[i];
        }
    }

    printf("larger %d\n", larger);
    free(array);
}