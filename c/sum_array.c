/**
 * Author: Devendra Naga <devendra.aaru@gmail.com
 * 
 * Copyright Apache License
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int var[40] = {0};
    int i;
    int sum = 0;

    for (i = 1; i < argc; i ++) {
        var[i] = atoi(argv[i]);
    }

    for (i = 0; i < sizeof(var) / sizeof(var[0]); i ++) {
        sum += var[i];
    }

    printf("sum [%d]\n", sum);
    return 0;
}
