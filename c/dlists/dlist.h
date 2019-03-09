/**
 * Author: Devendra Naga (devendra.aaru@gmail.com)
 * License: Apache
 */
#ifndef __DLIST_H__
#define __DLIST_H__

struct dlist {
    void *data;
    struct dlist *prev;
    struct dlist *next;
};

int dlist_add_tail(void *data);
int dlist_find_element(void *data);
int dlist_for_each_fwd(void (*foreach)(void *data));
int dlist_delete_item(void *data, void (*del)(void *data));
void dlist_free_all(void (*free_f)(void *data));

#endif
