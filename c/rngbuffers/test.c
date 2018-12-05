#include <stdio.h>
#include <rngbuf.h>

// print the rng buffer elements
void print_buf(void *data)
{
    int *d = data;

    printf("%d ", *d);
}


int main(int argc, char **argv)
{
    void *rngbuf;

    // initialise th e ring buffer with given size
    rngbuf = rngbuf_init(10);
    if (!rngbuf) {
        return -1;
    }

    // obviously the content length is large.. so we expect overwrites of the initial values
    int var[20];
    int i;

    int *ptr;

    // retriving a value from a rng buffer without adding any data results in a null return

    ptr = rngbuf_retrieve_elem(rngbuf);

    printf("ptr %p\n", ptr);

    for (i = 0; i < 20; i ++) {
        var[i] = i;

        // set element to the buffer../.
        rngbuf_add_elem(rngbuf, &var[i]);

        if (i % 2 == 0) {
            // retrieve for even number of times..
            rngbuf_retrieve_elem(rngbuf);
        }
    }

    // print the rngbuffer contents
    rngbuf_print_contents(rngbuf, print_buf);

    // free the rngbuf
    rngbuf_free(rngbuf);

    printf("\n");

    return 0;
}

