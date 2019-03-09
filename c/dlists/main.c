/**
 * Author: Devendra Naga (devendra.aaru@gmail.com)
 * License: Apache
 */
#include <stdio.h>
#include <dlist.h>

void print_items(void *data)
{
    int *ptr = data;

    printf("data : %d\n", *ptr);
}

int main()
{
    int a = 10;
    int b = 20;
    int c = 21;
    int d = 22;

    dlist_add_tail(&a);
    dlist_add_tail(&b);
    dlist_add_tail(&c);
    dlist_add_tail(&d);

    dlist_for_each_fwd(print_items);

    dlist_delete_item(&a, NULL);

    dlist_for_each_fwd(print_items);

    dlist_free_all(NULL);

    return 0;
}
