#include "linear_probing.h"
#include "generic.h"
#include <stdio.h>

void linearProbing() {
    int operation = 0;
    HashEntry hash_table[TABLE_SIZE] = {0};

    while ((operation = getChoice()) != QUIT) {
        switch (operation) {
            case INSERT:
                linearProbingInsert(hash_table);
                break;
            case SEARCH: {
                int target = 0;
                scanf("%d", &target);
                puts(linearProbingSearch(hash_table, target) ? "Found"
                                                             : "Not Found");
                break;
            }
            case DISPLAY:
                linearProbingDisplay(hash_table);
                break;
            default:
                break;
        }
    }
}

void linearProbingInsert(HashEntry hash_table[]) {
    int new_entry = 0;
    scanf("%d", &new_entry);

    int position = hashFunction1(new_entry);

    if (!hash_table[position].occupied) {
        hash_table[position].value = new_entry;
        hash_table[position].occupied = true;

        return;
    }

    if (hash_table[position].value == new_entry) {
        return;
    }

    for (int i = hashFunction1(position + 1); i != position;
         i = hashFunction1(i + 1)) {
        if (!hash_table[i].occupied) {
            hash_table[i].occupied = true;
            hash_table[i].value = new_entry;
            break;
        }

        if (hash_table[i].value == new_entry) {
            return;
        }
    }
}

bool linearProbingSearch(HashEntry hash_table[], int target) {
    int position = hashFunction1(target);
    if (!hash_table[position].occupied) {
        return false;
    }

    if (hash_table[position].value == target) {
        return true;
    }

    for (int i = hashFunction1(position + 1); i != position;
         i = hashFunction1(i + 1)) {
        if (!hash_table[i].occupied) {
            return false;
        }

        if (hash_table[i].value == target) {
            return true;
        }
    }

    return false;
}

void linearProbingDisplay(HashEntry hash_table[]) {
    puts("Index\tOccupied\tValue");

    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d\t%d\t\t%d\n", i, hash_table[i].occupied,
               hash_table[i].value);
    }

    puts("");
}
