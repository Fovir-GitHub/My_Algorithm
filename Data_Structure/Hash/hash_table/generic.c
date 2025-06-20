#include "generic.h"

int getChoice() {
    int operation = 0;
    scanf("%d", &operation);

    return operation;
}

int hashFunction1(int key) { return key % TABLE_SIZE; }

int hashFunction2(int key) { return R - (key % R); }
