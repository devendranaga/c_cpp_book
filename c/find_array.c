/**
 * Author: Devendra Naga <devendra.aaru@gmail.com
 * 
 * Copyright Apache License
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int array[20];
    int i;
    int var;

    if (argc != 2) {
        fprintf(stderr, "<%s> number\n", argv[0]);
        return -1;
    }

    var = atoi(argv[1]);

    for (i = 0; i < sizeof(array) / sizeof(array[0]); i ++) {
        array[i] = i + 2;
    }

    int elem = 0;

    for (i = 0; i < sizeof(array) / sizeof(array[0]); i ++) {
        if (var == array[i]) {
            elem = 1;
            break;
        }
    }

    if (elem) {
        printf("found element %d at index %d\n", array[i], i);
    } else {
        printf("cannot find element %d\n", var);
    }
}
