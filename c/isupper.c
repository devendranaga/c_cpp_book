#include <stdio.h>
#include <ctype.h>

int main()
{
    char letter = 'B';

    if (isupper(letter)) {
        printf("letter '%c' is upper..\n", letter);
    } else if (islower(letter)) {
        printf("letter '%c' is lower..\n", letter);
    } else {
        printf("letter '%c' is unknown\n", letter);
    }

}

