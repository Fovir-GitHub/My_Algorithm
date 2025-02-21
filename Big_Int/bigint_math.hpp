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

BigInt gcd(const BigInt & a, const BigInt & b)
{
    return (a % b == BigInt(0) ? b : gcd(b, a % b));
}

BigInt lcm(const BigInt & a, const BigInt & b)
{
    return a * b / gcd(a, b);
}

END_BIGINT_MATH