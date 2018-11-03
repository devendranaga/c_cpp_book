#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *fp;
    char input[1024];

    if (argc != 2) {
        fprintf(stderr, "<%s> file-to-write-to\n", argv[0]);
        return -1;
    }

    fp = fopen(argv[1], "w");
    if (!fp) {
        fprintf(stderr, "failed to open file in write mode %s\n", argv[1]);
        return -1;
    }

    fprintf(stderr, "write anything to dump in %s..\n", argv[1]);
    fgets(input, sizeof(input), stdin);
    fputs(input, fp);

    printf("successfully written to the file..\n");
    fflush(fp);
    fclose(fp);

    return 0;
}

