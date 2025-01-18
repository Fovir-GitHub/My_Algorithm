#include "bignumber.h"
#include <iostream>

int main(void)
{
    BigInt first, second;

    while (std::cin >> first >> second)
        std::cout << first << " + " << second << " = " << first + second
                  << '\n';

    return 0;
}