/**
 * Author: Devendra Naga (devendra.aaru@gmail.com)
 *
 * License Apache
 */
#include <stdio.h>
#include <stdlib.h>

int recursive_factorial(int n)
{
    if (n == 0) {
        return 1;
    }

    return n * recursive_factorial(n - 1);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "<%s> num\n", argv[0]);
        return -1;
    }

    printf("factorial %d\n", recursive_factorial(atoi(argv[1])));
    return 0;
}
