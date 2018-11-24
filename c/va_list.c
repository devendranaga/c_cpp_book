#include <stdio.h>
#include <stdarg.h>

int var_Arg_printf(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);

    return 0;
}

int main()
{
    var_Arg_printf("hello: hello world.. <test print> %d\n", 10);
}

