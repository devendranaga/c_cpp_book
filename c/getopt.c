
/**
 *  * @brief - program to read command line arguments with getopt
 *   *
 *    * @Author  Devendra Naga <devendra.aaru@gmail.com>
 *     *
 *      * @LICENSE Aapache
 *       */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    int ret;
    int opt_a = 0;
    int opt_b = 0;

    while ((ret = getopt(argc, argv, "a:b")) != -1) {
        switch (ret) {
            case 'a':
                opt_a = atoi(optarg);
            break;
            case 'b':
                opt_b = 1;
            break;
        }
    }

    printf("opt_a %d opt_b %d\n", opt_a, opt_b);

    return 0;
}

