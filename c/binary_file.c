/**
 * Written by Devendra Naga (devendra.aaru@gmail.com)
 *
 * License Apache
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    struct s {
        int a;
        int b;
    } __attribute__((__packed__));

    FILE *fp;
    struct s s[40];
    int i;

    if (argc != 2) {
        fprintf(stderr, "<%s> filename\n", argv[0]);
        return -1;
    }

    fp = fopen(argv[1], "wb");
    if (!fp) {
        return -1;
    }

    for (i = 0; i < sizeof(s) / sizeof(s[0]);  i ++) {
        s[i].a = i;
        s[i].b = i + 1;
        printf("put  -> s[%d].a = %d s[%d].b = %d\n", i, s[i].a, i, s[i].b);
    }
    fwrite(s, sizeof(s), 1, fp);
    fflush(fp);
    fclose(fp);

    fp = fopen(argv[1], "rb");
    if (!fp) {
        fprintf(stderr, "failed to open %s \n", argv[1]);
        return -1;
    }

    struct s s_[40];

    memset(s_, 0, sizeof(s_));
    fread(s_, sizeof(s_), 1, fp);

    for (i = 0; i < sizeof(s_) / sizeof(s_[0]); i ++) {
        printf("get -> s_[%d].a %d s_[%d].b %d\n", i, s_[i].a, i, s_[i].b);
    }


    fclose(fp);
    return 0;
}

