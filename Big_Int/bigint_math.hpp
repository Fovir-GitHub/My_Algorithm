#include "bigint.h"

#define START_BIGINT_MATH  \
    namespace big_int_math \
    {
#define END_BIGINT_MATH }


START_BIGINT_MATH

BigInt factorial(const BigInt & n)
{
    BigInt result("1");

    for (BigInt i = BigInt(1); i <= n; i++) result *= i;

    return result;
}

END_BIGINT_MATH