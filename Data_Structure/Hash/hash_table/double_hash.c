#include "./double_hash.h"
#include "generic.h"
#include <stdio.h>

static int doubleHashingFunction(int key, int i);

static int doubleHashingFunction(int key, int i) {
    return (hashFunction1(key) + i * hashFunction2(key)) % TABLE_SIZE;
}

void doubleHashing() {
    int operation = 0;
    HashEntry hash_table[TABLE_SIZE] = {0};

    while ((operation = getChoice()) != QUIT) {
        switch (operation) {
        case INSERT:
            doubleHashingInsert(hash_table);
            break;
        case SEARCH: {
            int target = 0;
            scanf("%d", &target);
            puts(doubleHashingSearch(hash_table, target) ? "Found"
                                                         : "Not Found");
            break;
        }
        case DISPLAY:
            doubleHashingDisplay(hash_table);
            break;
        default:
            break;
        }
    }
}

void doubleHashingInsert(HashEntry hash_table[]) {
    int new_value = 0;
    scanf("%d", &new_value);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int position = doubleHashingFunction(new_value, i);

        if (!hash_table[position].occupied) {
            hash_table[position].occupied = true;
            hash_table[position].value = new_value;
            break;
        }
    }
}

bool doubleHashingSearch(HashEntry hash_table[], int target) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        int position = doubleHashingFunction(target, i);

        if (!hash_table[position].occupied) {
            return false;
        }

        if (hash_table[position].value == target) {
            return true;
        }
    }

    return false;
}

void doubleHashingDisplay(HashEntry hash_table[]) {
    puts("Index\tOccupied\tValue");

    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d\t%d\t%d\n", i, hash_table[i].occupied, hash_table[i].value);
    }

    puts("");
}
