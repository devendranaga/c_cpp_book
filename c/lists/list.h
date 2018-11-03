/**
 * @Author: Devendra Naga (devendra.aaru@gmail.com)
 *
 * License Apache
 */
#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>

int linked_list_add_head(void *data);

int linked_list_add(void *data);

int linked_list_remove(void *data,
                       void (*remove_callback)(void *data));

int linked_list_find_item(void *data);

int linked_list_remove_all(void (*remove_callback)(void *data));

void linked_list_print(void (*print_callback)(void *data));

int linked_list_count();

#endif

