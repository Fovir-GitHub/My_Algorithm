#include "double_hash.h"
#include "generic.h"
#include "linear_probing.h"
#include "linked_list_hashing.h"
#include <stdio.h>

int main() {
    int collision_type = 0;

    printf("Please select type: ");
    scanf("%d", &collision_type);

    switch (collision_type) {
        case LINEAR_PROBING:
            linearProbing();
            break;
        case DOUBLE_HASHING:
            doubleHashing();
            break;
        case CHAINING:
            linkedListHashing();
            break;
        default:
            break;
    }
}
