#ifndef __HASH_TABL_H__
#define __HASH_TABL_H__

// free hash tables
void hash_table_free(void **hash_table, void (*delete_callback)(void *data));

// initialise hash tables.. give table_length_ as a number of rows in table
void** hash_table_init(int table_length_);

// print the max chain within the hash table
void hash_table_print_max_list();

// find the item based on the given algorithm
void *hash_table_find_item(void *item, uint32_t (*hash_algorithm)(void *item));

// print the hash table .. all elements
void hash_table_print(void (*print_func)(void *item));

// delete item from the hash table
int hash_table_delete_item(void *item,
                           uint32_t (*hash_algorithm)(void *item),
                           void (*delete_callback)(void *item));

// add item into the table .. a valid hash  algorithm must be there
int hash_table_add_item(void *item, uint32_t (*hash_algorithm)(void *item));

// print all elements of the hash tables
void hash_print(void *item);

#endif




