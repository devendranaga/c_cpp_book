#include <stdio.h>

int main()
{
    int type = 1;

    switch (type) {
        case 1:
            printf("in case1\n");
        case 2:
            printf("in case2\n");
        break;
        default:
            printf("in default\n");
        break;
    }
}

