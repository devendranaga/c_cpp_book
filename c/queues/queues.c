#include <stdio.h>
#include <stdlib.h>

struct queue_ds {
    void *data;
    struct queue_ds *next;
};

static struct queue_ds *head = NULL;
static struct queue_ds *tail = NULL;

int queue_add(void *data)
{
    struct queue_ds *new;

    new = calloc(1, sizeof(struct queue_ds));
    if (!new) {
        return -1;
    }

    new->data = data;

    if (!head) {
        head = new;
        tail = new;
    } else {
        tail->next = new;
        tail = new;
    }

    return 0;
}

int queue_get(void *priv, void (*retrieve)(void *data, void *priv))
{
    struct queue_ds *t = head;

    if (t) {
        retrieve(t->data, priv);

        head = t->next;
        free(t);

        return 0;
    }

    return -1;
}


