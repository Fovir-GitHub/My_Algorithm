#ifndef _GENERIC_H_
#define _GENERIC_H_

#include <stdbool.h>
#include <stdio.h>

#define TABLE_SIZE 11
#define R 7

typedef struct {
    int value;
    bool occupied;
} HashEntry;

enum {
    LINEAR_PROBING,
    DOUBLE_HASHING,
    CHAINING,
};

enum OPERATION {
    QUIT,
    INSERT,
    SEARCH,
    DISPLAY,
};

int getChoice();

int hashFunction1(int key);
int hashFunction2(int key);

#endif
