#ifndef __RNGBUF_H__
#define __RNGBUF_H__

// initialise the ring buffer with the given ring buffer size
void * rngbuf_init(int size);

// add an element to the ring, with the rng from rngbuf_init and the element
int rngbuf_add_elem(void *rng, void *elem);

// add elements but do not overwrite the content of the rngbuf
int rngbuf_add_elem_no_overwrite(void *rng, void *elem);

// retrieve the element from the ring buffer
void* rngbuf_retrieve_elem(void *rng);

// print the contents of the ring buffer
void rngbuf_print_contents(void *rng, void (*print_callback)(void *data));

// free the rng buffer
void rngbuf_free(void *rng);

#endif

