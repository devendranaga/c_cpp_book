#include <stdio.h>
#include <stdarg.h>

int va_arg_buf(char *buf, char *fmt, ...)
{
    va_list ap;
    int ret;

    va_start(ap, fmt);

    ret = vsprintf(buf, fmt, ap);

    va_end(ap);

    return ret;
}

int main()
{
    char buf[1200];

    va_arg_buf(buf, "test: this is a test %d", 10);

    fprintf(stderr, "buf output is '%s'\n", buf);
}

