/**
 * @brief - program to find the prime numbers from 0 to 400
 *
 * Author: Dev Naga <devendra.aaru@gmail.com>
 *
 * Apache LICENCE
 */
#include <stdio.h>

// we store all our primes in this
struct primes {
    int n;
    // flag that will be set to 1 when prime, and 0 if not prime
    int prime;
};

int main()
{
    int n = 100;
    int i;
    int j;
    struct primes p[500];

    // collect all the numbers
    for (i = 0; i <= 400; i ++) {
        p[i].n = i;
        p[i].prime = -1;
    }

    for (i = 2; i <= 400; i ++) {
        for (j = 0; j <= 400; j ++) {

            // for each number in p[j] modulo with i
            if (p[j].n % i == 0) {

                //
                //1. divisor selection is as such that it is not being marked off - p[j].prime = 0
                //2. mark divisor itself as a prime if p[j].n == i
                if ((p[j].prime == -1) && (p[j].n == i)) {
                    p[j].prime = 1;
                    continue;
                } else {
                    p[j].prime = 0;
                }
            }
        }
    }

    // print all the primes from 0 to 400
    for (i = 0; i <= 400; i ++) {
        if (p[i].prime == 1) {
            printf("%d ", p[i].n);
        }
    }
    printf("\n");
}