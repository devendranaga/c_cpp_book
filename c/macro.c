#include <stdio.h>

#define _PRINT_MSG_

int main()
{
#ifdef _PRINT_MSG_
    printf("hello macro..\n");
#endif

    return 0;
}

