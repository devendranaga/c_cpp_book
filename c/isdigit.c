#include <stdio.h>
#include <ctype.h>

int main()
{
    char dig_ = 'a';
    char digi_ = '1';

    if (isdigit(digi_)) {
        printf("the '%d' is a digit \n", digi_);
    } else {
        printf("the '%d' is not a digit \n", digi_);
    }

    if (isxdigit(dig_)) {
        printf("the '%d' is a hexadecimal \n", dig_);
    } else {
        printf("the '%d' is not a hexadecimal \n", dig_);
    }
}

