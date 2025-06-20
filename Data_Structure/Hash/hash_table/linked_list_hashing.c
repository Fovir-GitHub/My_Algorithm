#include "./linked_list_hashing.h"
#include "generic.h"
#include <stdio.h>
#include <stdlib.h>

static Node * makeNode(int value);

static Node * makeNode(int value) {
    Node * node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    return node;
}

void initializeLinkedList(LinkedList * plist) { *plist = NULL; }

void insertLinkedList(LinkedList * plist, int new_value) {
    if (*plist == NULL) {
        *plist = makeNode(new_value);
        return;
    }

    for (Node * node = *plist; node; node = node->next) {
        if (node->value == new_value) {
            return;
        }

        if (!node->next) {
            node->next = makeNode(new_value);
        }
    }
}

bool searchLinkedList(LinkedList * plist, int target) {
    for (Node * node = *plist; node; node = node->next) {
        if (node->value == target) {
            return true;
        }
    }

    return false;
}

void displayLinkedList(LinkedList * plist) {
    for (Node * node = *plist; node; node = node->next) {
        printf("%d ", node->value);
    }

    puts("");
}

void freeLinkedList(LinkedList * plist) {
    Node * backup = *plist;
    while (*plist) {
        backup = (*plist)->next;
        free(*plist);
        *plist = backup;
    }
}

void linkedListHashing() {
    LinkedList hash_table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        initializeLinkedList(&hash_table[i]);
    }

    int operation = 0;
    while ((operation = getChoice()) != QUIT) {
        switch (operation) {
        case INSERT: {
            int new_value = 0;
            scanf("%d", &new_value);
            insertLinkedList(&hash_table[new_value % TABLE_SIZE], new_value);
            break;
        }
        case SEARCH: {
            int target = 0;
            scanf("%d", &target);
            puts(searchLinkedList(&hash_table[target % TABLE_SIZE], target)
                     ? "Found"
                     : "Not Found");
            break;
        }
        case DISPLAY:
            for (int i = 0; i < TABLE_SIZE; i++) {
                displayLinkedList(&hash_table[i]);
            }
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        freeLinkedList(&hash_table[i]);
    }
}
