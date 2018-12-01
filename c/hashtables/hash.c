#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <hash.h>

struct hash_chain {
    void *data;
    uint32_t hash_val;
    struct hash_chain *next;
};

// the hash table that holds all the buckets
struct hash_table {
    // this is incremented everytime a new
    int list_count;

    // head of bucket containing a list of elements
    struct hash_chain *bucket;

    // last element of the bucket for easy add
    struct hash_chain *bucket_last;
};

static int table_length;
struct hash_table **table;

// free the hash table and the internal references
void hash_table_free(void **hash_table, void (*delete_callback)(void *item))
{
    int i;

    // for each hash table

    for (i = 0; i < table_length; i ++) {

        struct hash_chain *chain , *prev;

        // for each chain in the hash table
        chain = prev = table[i]->bucket;

        while (chain) {
            // point prev to the chain
            prev = chain;

            // make chain point to next
            chain = chain->next;

            // call delete callback back to the caller
            if (delete_callback) {
                delete_callback(prev->data);
            }

            // free the prev
            free(prev);
        }

        //free the table at this index
        free(table[i]);
    }

    // free the entire allocated table
    free(table);
}

// initialise the hash table pointer
void** hash_table_init(int table_length_)
{
    int i;

    // copy the tbl length
    table_length = table_length_;

    // allocate a double pointer table array
    table = calloc(table_length, sizeof(struct hash_table));
    if (!table) {
        fprintf(stderr, "failed to allocate @ %s %u\n", __func__, __LINE__);
        return NULL;
    }

    for (i = 0; i < table_length; i ++) {
        table[i] = calloc(1, sizeof(struct hash_table));
        if (!table[i]) {
            fprintf(stderr, "failed to allocate @ %s %u\n", __func__, __LINE__);
            return NULL;
        }

        // set all buckets in the table to null.. allocated in the additem call
        table[i]->bucket = NULL;
        table[i]->bucket_last = NULL;
    }

    // return the table
    return (void **)table;
}

// print the max chain length that is created 
void hash_table_print_max_list()
{
    int i;
    int max = 0;

    for (i = 0; i < table_length; i ++) {
        if (max < table[i]->list_count) {
            max = table[i]->list_count;
        }
    }

    printf("max %d\n", max);
}

// find item in the hash table
void *hash_table_find_item(void *item, uint32_t (*hash_algorithm)(void *item))
{
    struct hash_chain *new = NULL;
    void *obj = NULL;
    uint32_t hash_val;
    int i;
    int iterations_j = 0;

    // call the hash algorithm to get the matching hash
    hash_val = hash_algorithm(item) % table_length;

    // iterate over the list to find where the element is
    for (new = table[hash_val]->bucket; new; new = new->next) {

        iterations_j ++;

        // element found.. break the loop
        if (new->data == item) {
            obj = new->data;
            break;
        }
    }

    // return the item
    printf("took %d iterations \n", iterations_j);
    return obj;
}

// delete an item from the hash table
int hash_table_delete_item(void *item,
                           uint32_t (*hash_algorithm)(void *item),
                           void (*delete_callback)(void *item))
{
    struct hash_chain *cur = NULL, *prev = NULL;
    uint32_t hash_val;

    // call the hash algorithm to get the matching hash
    hash_val = hash_algorithm(item) % table_length;

    cur = table[hash_val]->bucket;
    prev = cur;

    // if head element is the matching hash .. move head to next
    //
    //
    // make head point to the next element and return true
    if (cur->data == item) {
        table[hash_val]->bucket = cur->next;
        printf("delete %p\n", cur);
        if (delete_callback) {
            delete_callback(cur->data);
        }
        free(cur);
        return 1;
    }

    // if the middle elementis the element in the list to be deleted..
    //
    while (cur) {
        if (cur->data == item) {
            prev->next = cur->next;

            printf("delete %p\n", cur);
            // make next pointer of prev point to the next of the element to be deleted
            //
            // call delete callback to let the caller know that element is deleted
            if (delete_callback) {
                delete_callback(cur->data);
            }

            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }

    return 0;
}

// print the elements of the hash table
void hash_table_print(void (*print_func)(void *item))
{
    int i;

    for (i = 0; i < table_length; i ++) {
        struct hash_chain *new;

        for (new = table[i]->bucket; new; new = new->next) {

            print_func(new->data);

        }
    }
}

// add an item in the hash table
int hash_table_add_item(void *item, uint32_t (*hash_algorithm)(void *item))
{
    uint32_t hash_value;

    // if no hash algorithm.. item cannot be added !
    if (!hash_algorithm) {
        fprintf(stderr, "no hash algorithm @ %s %u\n", __func__, __LINE__);
        return -1;
    }

    // hash value shall always be modyulo table size
    hash_value = hash_algorithm(item) % table_length;

    struct hash_chain *new;

    // allocate new element
    new = calloc(1, sizeof(struct hash_chain));
    if (!new) {
        fprintf(stderr, "failed to allocate @ %s %u\n", __func__, __LINE__);
        return -1;
    }

    new->data = item;
    new->hash_val = hash_value;

    // check if the bucket is already have a first element .. its a collision
    //
    // so add element to the next of the bucket by using last 
    if (table[hash_value]->bucket) {
        table[hash_value]->bucket_last->next = new;
        table[hash_value]->bucket_last = new;
        table[hash_value]->list_count ++;
    } else {
        table[hash_value]->bucket = new;
        table[hash_value]->bucket_last = new;
        table[hash_value]->list_count ++;
    }

    return 0;
}


