/**
 * Author: Devendra Naga <devendra.aaru@gmail.com
 * 
 * Copyright Apache License
 */
#include <stdio.h>

int main()
{
    int a[44];
    int i;

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
        a[i] = i;
    }

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
}
