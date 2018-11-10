#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool a = false;

    if (a == false) {
        printf("a is false\n");
        a = true;
    }

    if (a == true) {
        printf("a is true\n");
    }

    return 0;
}

