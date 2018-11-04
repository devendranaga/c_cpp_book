/**
 * Author: Devendra Naga (devendra.aaru@gmail.com)
 *
 * License Apache
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int var;
    int first = 0;
    int second = 1;
    int res = 0;

    if (argc != 2) {
        fprintf(stderr, "<%s> number\n", argv[0]);
        return -1;
    }

    var = atoi(argv[1]);


    int i;

    printf("%d ", first);
    for (i = 0; i < var; i ++) {
        res = first + second;
        first = second;
        second = res;
        printf("%d ", res);
    }

    printf("\n");
}
