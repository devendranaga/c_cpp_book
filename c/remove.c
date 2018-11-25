#include <stdio.h>

int main(int argc, char **argv)
{
    int ret;

    if (argc != 2) {
        fprintf(stderr, "<%s> filename\n", argv[0]);
        return -1;
    }

    ret = remove(argv[1]);
    if (ret < 0) {
        fprintf(stderr, "failed to remove %s\n", argv[1]);
        return -1;
    }

    return 0;
}

