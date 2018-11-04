/**
 * Author: Devendra Naga <devendra.aaru@gmail.com
 * 
 * Copyright Apache License
 */
#include <stdio.h>

int main()
{
    int a[4] = {1};
    int i;

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
        printf("%d\n", a[i]);
    }
}
