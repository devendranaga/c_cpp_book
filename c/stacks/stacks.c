#include <stdio.h>
#include <stdlib.h>

//stack data structure in linked list
struct stack_ds {
    void *data;
    struct stack_ds *next;
};

static struct stack_ds *head = NULL;

// initialise the stack head pointer
void stack_init()
{
    head = NULL;
}

// add elements to the stack
int stack_add(void *elem)
{
    struct stack_ds *new;
    struct stack_ds *t;

    // allocate new element
    new = calloc(1, sizeof(struct stack_ds));
    if (!new) {
        return -1;
    }

    // set data
    new->data = elem;

    if (!head) { // add new element to the head
        head = new;
    } else {
        t = head;

        while (t->next)
            t = t->next;

        t->next = new;
    }

    printf("add_ptr %p\n", new);

    return 0;
}

// retrieve elements from the last
int stack_retrieve(void *priv, void (*retrieve_cb)(void *data, void *priv))
{
    struct stack_ds *t;
    struct stack_ds *t_1;

    t_1 = head;
    t = head;

    // no elements so fail
    if (!t)
        return -1;

    // reach at the end of the stack
    while (t->next) {
        t_1 = t;
        t = t->next;
    }

    // retrieve the end element ..  and call the correspnding callback
    retrieve_cb(t->data, priv);

    // free it
    free(t);

    // if element is head then we must set head to NULL
    if (t == head) {
        t = NULL;
        t_1 = NULL;
        head = NULL;
    }

    // set next of the last but one pointers to NULL..
    if (t_1)
        t_1->next = NULL;

    return 0;
}

