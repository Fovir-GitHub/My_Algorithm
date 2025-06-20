#ifndef _DOUBLE_HASH_H_
#define _DOUBLE_HASH_H_

#include "./generic.h"

void doubleHashing();

void doubleHashingInsert(HashEntry hash_table[]);

bool doubleHashingSearch(HashEntry hash_table[], int target);

void doubleHashingDisplay(HashEntry hash_table[]);

#endif
