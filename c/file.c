/**
 * Author Devendra Naga (devendra.aaru@gmail.com)
 *
 * License apache
 */
#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *fp1, *fp2;

    fp1 = fopen(argv[1], "r");
    if (!fp1) {
        fprintf(stderr, "failed to open %s\n", argv[1]);
        return -1;
    }

    fp2 = fopen(argv[2], "w");
    if (!fp2) {
        fprintf(stderr, "failed to open %s\n", argv[2]);
        return -1;
    }

    char buf[1024];

    while (fgets(buf, sizeof(buf), fp1)) {
        fprintf(fp2, "%s", buf);
    }

    printf("copy success\n");
    fflush(fp2);
    fclose(fp2);
    fclose(fp1);

    return 0;
}
