#include "bigint.h"
#include "bigint_math.hpp"
#include <iostream>

int main(void) {
    BigInt n;

    while (std::cin >> n)
        big_int_math::primeFactorize(n);

    return 0;
}