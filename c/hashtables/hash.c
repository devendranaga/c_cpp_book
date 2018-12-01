#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

struct hash_chain {
    void *data;
    uint32_t hash_val;
    struct hash_chain *next;
};

struct hash_table {
    int list_count;
    struct hash_chain *bucket;
    struct hash_chain *bucket_last;
};

static int table_length;
struct hash_table **table;

void hash_table_free(void **hash_table)
{
    int i;

    for (i = 0; i < table_length; i ++) {

        struct hash_chain *chain , *prev;

        chain = prev = table[i]->bucket;

        while (chain) {
            prev = chain;
            chain = chain->next;
            free(prev);
        }

        free(table[i]);
    }

    free(table);
}

void** hash_table_init(int table_length_)
{
    int i;

    table_length = table_length_;
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

        table[i]->bucket = NULL;
        table[i]->bucket_last = NULL;
    }

    return (void **)table;
}

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

void *hash_table_find_item(void *item, uint32_t (hash_algorithm)(void *item))
{
    struct hash_chain *new = NULL;
    void *obj = NULL;
    uint32_t hash_val;
    int i;
    int iterations_j = 0;

    hash_val = hash_algorithm(item) % table_length;

    for (new = table[hash_val]->bucket; new; new = new->next) {

        iterations_j ++;

        if (new->data == item) {
            obj = new->data;
            break;
        }
    }

    printf("took %d iterations \n", iterations_j);
    return obj;
}

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

int hash_table_add_item(void *item, uint32_t (*hash_algorithm)(void *item))
{
    uint32_t hash_value;

    if (!hash_algorithm) {
        fprintf(stderr, "no hash algorithm @ %s %u\n", __func__, __LINE__);
        return -1;
    }

    hash_value = hash_algorithm(item) % table_length;

    struct hash_chain *new;

    new = calloc(1, sizeof(struct hash_chain));
    if (!new) {
        fprintf(stderr, "failed to allocate @ %s %u\n", __func__, __LINE__);
        return -1;
    }

    new->data = item;
    new->hash_val = hash_value;

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

void hash_print(void *item)
{
    int *i = item;

    printf("%d ", *i);
}


