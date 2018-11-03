/**
 * @brief - program to find the prime numbers from 0 to 400
 *
 * Author: Dev Naga <devendra.aaru@gmail.com>
 *
 * MIT LICENCE
 */
#include <stdio.h>
#include <stdlib.h>

struct linked_list {
    void *data;
    struct linked_list *next;
};

static struct linked_list *head = NULL;
static struct linked_list *tail = NULL;

int linked_list_add(void *data)
{
    struct linked_list *item;

    item = calloc(1, sizeof(struct linked_list));
    if (!item) {
        fprintf(stderr, "failed to allocate @ %s %u\n", __func__, __LINE__);
        return -1;
    }

    item->data = data;
    
    if (!head) {
        head = item;
        tail = item;
    } else {
        tail->next = item;
        tail = item;
    }

    return 0;
}

int linked_list_add_head(void *data)
{
    struct linked_list *item;

    item = calloc(1, sizeof(struct linked_list));
    if (!item) {
        return -1;
    }

    item->data = data;

    if (!head) {
        head = item;
        tail = item;
    } else {
        item->next = head;
        head = item;
    }

    return 0;
}

int linked_list_remove(void *data,
                       void (*remove_callback)(void *data))
{
    struct linked_list *cur;
    struct linked_list *prev;

    cur = head;

    if (cur->data == data) {
        head = cur->next;
        remove_callback(cur->data);
        free(cur);
        return 0;
    }

    while (cur) {
        if (cur->data == data) {
            prev->next = cur->next;
            remove_callback(cur->data);
            free(cur);
            return 0;
        }
        prev = cur;
        cur = cur->next;
    }

    return -1;
}

/**
 * return 1 if an item found or 0 if not
 */
int linked_list_find_item(void *data)
{
    struct linked_list *cur;

    for (cur = head; cur; cur = cur->next) {
        if (cur->data == data) {
            return 1;
        }
    }

    return 0;
}

int linked_list_remove_all(void (*remove_callback)(void *data))
{
    struct linked_list *cur;
    struct linked_list *prev;

    cur = head;

    while (cur) {
        prev = cur;
        remove_callback(cur->data);
        cur = cur->next;
        free(prev);
    }
}

void linked_list_print(void (*print_callback)(void *data))
{
    struct linked_list *item;

    for (item = head; item; item = item->next) {
        print_callback(item->data);
    }
}

int linked_list_count()
{
    struct linked_list *cur;
    int count = 0;

    for (cur = head; cur; cur = cur->next) {
        count ++;
    }

    return count;
}
