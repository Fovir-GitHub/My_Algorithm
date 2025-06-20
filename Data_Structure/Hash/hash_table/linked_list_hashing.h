#ifndef _LINKED_LIST_HASHING_H_
#define _LINKED_LIST_HASHING_H_

#include "./generic.h"

typedef struct Node {
    int value;
    struct Node * next;
} Node;

typedef Node * LinkedList;

void initializeLinkedList(LinkedList * plist);

void insertLinkedList(LinkedList * plist, int new_value);

bool searchLinkedList(LinkedList * plist, int target);

void displayLinkedList(LinkedList * plist);

void freeLinkedList(LinkedList * plist);

void linkedListHashing();

#endif
