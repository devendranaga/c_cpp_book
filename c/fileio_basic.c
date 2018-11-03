/**
 * Author : Devendra Naga (devendra.aaru@gmail.com)
 *
 * License apache
 */
#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *fp;
    
    if (argc != 2) {
        fprintf(stderr, "<%s filename>\n", argv[0]);
        return -1;
    }
 
    // open the file given from command line
    fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "failed to open %s \n", argv[1]);
        return -1;
    }
    
    char buf[1024];
    
    while (fgets(buf, sizeof(buf), fp)) {
        printf("input <%s>\n", buf);
    }
    
    fclose(fp);
    
    return 0;
}

