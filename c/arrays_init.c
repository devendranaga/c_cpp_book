/**
 * Author: Devendra Naga <devendra.aaru@gmail.com
 * 
 * Copyright Apache License
 */
#include <stdio.h>

int main()
{
    int i;
    int a[4];

    a[0] = 1;
    a[3] = 1;

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
        printf("%d\n", a[i]);
    }
}
