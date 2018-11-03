
/**
 * @brief - size of two-dimensional array
 *
 * Author: Dev Naga <devendra.aaru@gmail.com>
 *
 * Apache LICENCE
 */
#include <stdio.h>

int main()
{
    int a[4][8];
    int size;

    // rows 
    size = sizeof(a) / sizeof(a[0]);
    // cols 
    size *= sizeof(a[0]) / sizeof(a[0][0]);

    printf("total size %d\n", size);
}
