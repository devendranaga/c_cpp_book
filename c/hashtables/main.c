#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <hash.h>

uint32_t hash_this(void *item)
{
    int *val = item;
    char *magic = "abrownfoxjumpsoveralazy";
    uint32_t hash_val = 0;
    int i;

    for (i = 0; i < strlen(magic); i ++) {
        hash_val += (*val) + magic[i];
    }

    return hash_val;
}

int main(int argc, char **argv)
{
    void **hash_tbl;
    int i;

    // initialise the hash table with 100 elements
    hash_tbl = hash_table_init(100);
    if (!hash_tbl) {
        fprintf(stderr, "failed to hash_table_init @ %s %u\n", __func__, __LINE__);
        return -1;
    }

    // the elements to be set into hash talbe..
    //
    // see that the length is 4214 which is 42 times that of the hash table size..
    //
    // guaranteeing the collisions .. so need a stronger hash to distribute the elements uniformly so that even though
    // collisions are present, the values will be distributed across all memory locations reducing the iteratios overall
    int var[4214];

    for (i = 0; i < 4214; i ++) {
        var[i] = i;

        // add each item in the hash table
        hash_table_add_item(&var[i], hash_this);
    }

    // print the hash tables .. 
    //
    // see that the printing is from the hash begin to end not in the order the elements are added
    hash_table_print(hash_print);

    printf("\n");

    int *item;

    // find and print element in the hash table
    item = hash_table_find_item(&var[99], hash_this);
    if (item) {
        printf("item %d\n", *item);
    }

    // maximum size of a chain within the hash table due to collision

    hash_table_print_max_list();

    // free all hash table elements.. run it through valgrind
    //
    hash_table_free(hash_tbl);
}


