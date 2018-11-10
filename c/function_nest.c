/**
 * Author Devendra Naga (devendra.aaru@gmail.com)
 *
 * License Apache
 */
#include <stdio.h>

int main()
{
    int f()
    {
        printf("hello function\n");

        int f1()
        {
            printf("in function 1\n");

            return 0;
        }

        f1();

        return 0;
    }


    f();
    return 0;
}

