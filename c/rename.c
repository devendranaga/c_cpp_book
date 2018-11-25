#include <stdio.h>

int main(int argc, char **argv)
{
    int ret;

    if (argc != 3) {
        fprintf(stderr, "<%s> filename newfile\n", argv[0]);
        return -1;
    }

    ret = rename(argv[1], argv[2]);
    if (ret) {
        fprintf(stderr, "failed to rename %s to %s\n", argv[1], argv[2]);
        return -1;
    }

    return 0;
}

