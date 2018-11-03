/**
 * Author: Devendra Naga (devendra.aaru@gmail.com)
 *
 * License apache
 */
#include <stdio.h>
#include <stdlib.h>
#include <list.h>

void remove_callback(void *data)
{
    free(data);
}

void print_items(void *data)
{
    int *a = data;

    printf("%d\n", *a);
}

int main(int argc, char **argv)
{
    int i;
    int *one;
    int *two;
    int *three;

    for (i = 0; i < 10; i ++) {
        int *a;

        a = calloc(1, sizeof(*a));
        if (!a) {
            return -1;
        }

        *a = i + 1;

        // take copies of addresses for further deletes
        if (i == 0) {
            one = a;
        } else if (i == 1) {
            two = a;
        } else if (i == 2) {
            three = a;
        }

        linked_list_add(a);
    }

    printf("print list: %d\n", linked_list_count());

    linked_list_print(print_items);

    printf("delete elements 1, 2 and 3\n");

    linked_list_remove(one, remove_callback);
    linked_list_remove(two, remove_callback);
    linked_list_remove(three, remove_callback);

    printf("print list: %d\n", linked_list_count());

    linked_list_print(print_items);

    printf("remove all items\n");

    linked_list_remove_all(remove_callback);

    return 0;
}
