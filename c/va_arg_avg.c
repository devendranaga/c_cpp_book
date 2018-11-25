#include <stdio.h>
#include <stdarg.h>

int avg(int arg_count, ...)
{
    double sum = 0.0;
    int i;

    va_list ap;


    va_start(ap, arg_count);

    for (i = 0; i < arg_count; i ++) {
        double _val = va_arg(ap, double);

        sum += _val;
    }

    va_end(ap);

    fprintf(stderr, "avg: %f\n", sum / arg_count);

    return 0;
}

int main()
{
    avg(6, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);
}

