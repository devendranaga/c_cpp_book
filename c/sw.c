/**
 * 
 * demo program for a sliding window algorithm
 *
 * Author: Devendra Naga <devendra.aaru@gmail.com>
 * 
 * Copyright: Apache
 */
#include <stdio.h>
#include <stdlib.h>

// sliding window list
struct sliding_window {
    void *data;
    struct sliding_window *next;
};

struct sliding_window_ds {
    int length; // set up length of the sliding window

    // head is moved and head is always oldest data
    struct sliding_window *head;

    // current point is always have latest data
    struct sliding_window *cur;
    // old pointer for making links
    struct sliding_window *prev;
};

// create a fixed sliding window of given length
void * sliding_window_create(int size)
{
    struct sliding_window_ds *sw;

    // allocate base datastruct
    sw = calloc(1, sizeof(struct sliding_window_ds));
    if (!sw) {
        return NULL;
    }

    sw->length = size;

    int i;

    struct sliding_window *tail;

    // create a chain of fixed length
    for (i = 0; i < size; i ++) {
        struct sliding_window *s;

        s = calloc(1, sizeof(struct sliding_window));
        if (!s) {
            return NULL;
        }

        if (!sw->head) {
            sw->head = s;
            tail = s;
        } else {
            tail->next = s;
            tail = s;
        }
    }

    // point the cur to head
    sw->cur = sw->head;

    return sw;
}


// append new element at the cur
int sliding_window_append(void *ctx, void *data)
{
    struct sliding_window_ds *sw = ctx;

    // if cur is NIL.. 
    if (!sw->cur) {
        struct sliding_window *t = sw->head;

        // move head to the next older data
        sw->head = sw->head->next;

        // take the head pointer and point to cur
        sw->cur = t;
        sw->cur->next = NULL;

        // make a link between last element and the new pointer
        sw->prev->next = sw->cur;
    }

    // set data and prev chain follower
    sw->cur->data = data;
    sw->prev = sw->cur;
    sw->cur = sw->cur->next;

    return 0;
}

// free all pointers and cleanup
void sliding_window_free(void *ctx, void (*cb)(void *data))
{
    struct sliding_window_ds *sw = ctx;
    struct sliding_window *cur, *old;

    cur = sw->head;

    while (cur) {
        old  = cur;
        cur = cur->next;
        cb(old->data);
        free(old);
    }

    free(sw);
}

// printer .. 
void sliding_window_print(void *ctx, void (*print_callback)(void *data))
{
    struct sliding_window_ds *sw = ctx;
    struct sliding_window *s;

    s = sw->head;

    while (s) {
        if (s->data)
            print_callback(s->data);
        s = s->next;
    }
}

// for each ..
void sliding_window_for_each(void *ctx, void (*for_each_cb)(void *data))
{
    struct sliding_window_ds *sw = ctx;
    struct sliding_window *s;

    s = sw->head;

    while (s) {
        if (s->data)
            for_each_cb(s->data);
        s = s->next;
    }
}

void print(void *data)
{
    int *i = data;

    printf("%d\n", *i);
}

void cb(void *data)
{

}

int main()
{
    void *sw;

    sw = sliding_window_create(14);
    if (!sw) {
        return -1;
    }

    int i;
    int array[20];

    // we expect that 6 elements will be slided out
    for (i = 0; i < 20; i ++) {
        array[i] = i;
        sliding_window_append(sw, &array[i]);
    }

    sliding_window_print(sw, print);
    sliding_window_free(sw, cb);
}
