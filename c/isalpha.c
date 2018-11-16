#include <stdio.h>
#include <ctype.h>

int main()
{
    char char_ = 'a';
    char char1_ = '0';
    char char2_ = ' ';

    if (isalpha(char_)) {
        printf("character '%c' is a alphabet\n", char_);
    } else {
        printf("character '%c' is not an alphabet \n", char_);
    }

    if (isalnum(char1_)) {
        printf("character '%c' is an alphanumeric\n", char1_);
    } else {
        printf("character '%c' is not an alphanumberic\n", char1_);
    }

    if (isspace(char2_)) {
        printf("character '%c' is a space\n", char2_);
    } else {
        printf("character '%c' is not a space\n", char2_);
    }
}

