/**
 * @Author: Devendra Naga <devendra.aaru@gmail.com>
 * 
 * License Apache
 */
#include <stdio.h>

int main()
{
    int a[44]; // 44 elements of integers
    int i;

    // print addresses of each element that is present in the array
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
        printf("a[%d] = %p\n", i, a + i);
    }
}
