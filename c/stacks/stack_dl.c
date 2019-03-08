#include <stdio.h>
#include <stdlib.h>
#include <stack_dl.h>

static struct stack_dl *head, *tail;

int stack_push(void *data)
{
    struct stack_dl *node;

    node = calloc(1, sizeof(struct stack_dl));
    if (!node) {
        return -1;
    }

    node->data = data;

    if (!head) {
        head = node;
        tail = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }

    return 0;
}

void *stack_pop()
{
    struct stack_dl *node;
    void *data;

    node = head;
    if (!head)
        return NULL;

    data = node->data;

    if (head->next)
        head->next->prev = NULL;

    head = head->next;

    free(node);

    return data;
}

int main()
{
    int i;
    int array[40];

    for (i = 0; i < 40; i ++) {
        array[i] = i;

        stack_push(&array[i]);
    }

    while (1) {
        int *ptr = stack_pop();

        if (!ptr) {
            break;
        }

        printf("%d\n", *ptr);
    }

    return 0;
}

