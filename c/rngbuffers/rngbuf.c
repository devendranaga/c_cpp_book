#include <stdio.h>
#include <stdlib.h>

// ring buffer 
struct rngbuf_priv {
    // list of pointers to store in the ring
    void **data;
    // count of buffers with in this ring
    int size;

    // read end of the buf
    int head;

    // write end of the buf
    int tail;
};

// initialise the ring buffer and  setup the read and write offsets
void * rngbuf_init(int size)
{
    struct rngbuf_priv *priv;
    int i;

    priv = calloc(1, sizeof(struct rngbuf_priv));
    if (!priv) {
        return NULL;
    }

    // initialise the pointer addrtess array..
    //
    // chose long because it size is different in 32 bits and 64 bits system and so as the pointer addresses
    priv->data = calloc(size, sizeof(long *));
    if (!priv->data) {
        return NULL;
    }

    // reset the pointer addresses
    for (i = 0; i < size; i ++) {
        priv->data[i] = NULL;
    }

    // set the size of the ring
    priv->size = size;

    // reset head and tail offsets
    priv->head = 0;
    priv->tail = 0;

    return priv;
}

// add element to the ring.. do not fail
int rngbuf_add_elem(void *rng, void *elem)
{
    struct rngbuf_priv *priv = rng;

    priv->data[priv->tail] = elem;

    printf("add at %d val %d\n", priv->tail, (*(int *)elem));

    // increment tail to modulo .. so if the buf is full.. tail next value is the initial position of the buf
    priv->tail = (priv->tail + 1) % priv->size;

    return 0;
}

// do not overwrite when adding elements to the ring
int rngbuf_add_elem_no_overwrite(void *rng, void *elem)
{
    struct rngbuf_priv *priv = rng;

    // if there is a pointer then do not overwrite
    if (priv->data[priv->tail]) {
        printf("element exist.. failing\n");
        return -1;
    }

    // add element
    priv->data[priv->tail] = elem;

    printf("add at %d val %d\n", priv->tail, (*(int *)elem));

    // increment the tail to modulo..
    priv->tail = (priv->tail + 1) % priv->size;

    return 0;
}

// retrieve element from the rng
void* rngbuf_retrieve_elem(void *rng)
{
    struct rngbuf_priv *priv = rng;
    void *elem;

    elem = priv->data[priv->head];

    // consume and reset the position
    priv->data[priv->head] = NULL;

    if (elem) {
        printf("retrieved at %d value %d\n", priv->head, (*(int *)elem));
    }

    // increment head modulo the ring buffer size
    priv->head = (priv->head + 1) % priv->size;

    // return the retrived element
    return elem;
}

// print the ring buffer contents
void rngbuf_print_contents(void *rng, void (*print_callback)(void *data))
{
    struct rngbuf_priv *priv = rng;
    int i;

    for (i = 0; i < priv->size; i ++) {
        if (priv->data[i] != NULL) {
            // callback to call the printer
            print_callback(priv->data[i]);
        }
    }

}

// free the ring buffer done via the ringbuf_init
void rngbuf_free(void *rng)
{
    struct rngbuf_priv *priv = rng;

    free(priv->data);
    free(priv);
}

