/**
 * Author: Devendra Naga (devendra.aaru@gmail.com)
 * License: Apache
 */
#include <stdio.h>
#include <dlist.h>
#include <stdlib.h>

static struct dlist *head;
static struct dlist *tail;

// add an element to the tail
//
int dlist_add_tail(void *data)
{
    struct dlist *new_node;

    // alloc new node
    new_node = calloc(1, sizeof(struct dlist));
    if (!new_node) {
        return -1;
    }


    // set the data pointer
    new_node->data = data;

    // first element
    if (!head) {
        // set head and tail pointers
        head = new_node;
        tail = new_node;
    } else {
        // add new node to the last (forwards link)
        tail->next = new_node;

        // make a link of the prev pointer to the tail (backwards link)
        new_node->prev = tail;

        // make tail point to the new node..
        tail = new_node;
    }

    return 0;
}

// find an elementin the list
//
int dlist_find_element(void *data)
{
    struct dlist *t;

    // for each element compare the data pointer
    for (t = head; t; t = t->next) {
        if (t->data == data)
            return 1;
    }

    return 0;
}

// iterate through the list and call the foreach function pointer for every
// item
//
int dlist_for_each_fwd(void (*foreach)(void *data))
{
    struct dlist *t;

    if (!foreach)
        return -1;

    for (t = head; t; t = t->next) {
        foreach(t->data);
    }

    return 0;
}

// delete an element from the list
int dlist_delete_item(void *data, void (*del)(void *data))
{
    struct dlist *t;
    struct dlist *prev;

    t = head;

    // if the element is head
    if (t->data == data) {

        // call del callback on the element
        if (del)
            del(t->data);

        // make head point to the next node
        head = t->next;

        // make the next node's backwards point to the head .. so a full chain is created
        t->next->prev = head;

        free(t);

        return 0;
    }

    prev = t;

    // otherwise we are in a iteration to find an element
    while (t) {
        // element is found
        if (t->data == data) {

            // call del callback on the element
            if (del)
                del(t->data);

            // make the prev pointing to the next of the element to be deleted
            prev->next = t->next;

            // make a backwards point to the prev.. so a full chain is created
            t->next->prev = prev;

            free(t);
            return 0;
        }

        // iterate
        prev = t;
        t = t->next;
    }

    return -1;
}

// free all the nodes in the list
void dlist_free_all(void (*free_f)(void *data))
{
    struct dlist *t;
    struct dlist *prev;

    t = head;

    // iterate for each node
    while (t) {
        // set previous to current t
        prev = t;

        // call the free callback on each node's data pointer
        if (free_f)
            free_f(t->data);

        // make current t point to next
        t = t->next;

        // free the prev
        free(prev);
    }

}
