#ifndef _LINEAR_PROBING_H_
#define _LINEAR_PROBING_H_

#include "./generic.h"

void linearProbing();
void linearProbingInsert(HashEntry hash_table[]);
bool linearProbingSearch(HashEntry hash_table[], int target);
void linearProbingDisplay(HashEntry hash_table[]);

#endif
