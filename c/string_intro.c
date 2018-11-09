#include <stdio.h>

int main()
{
    char string[] = "hello C";

    printf("printing with printf '%s'\n", string);
    fprintf(stderr, "printing with fprintf '%s'\n", string);

    return 0;
}

