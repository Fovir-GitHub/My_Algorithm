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

bool isPrime(const BigInt & n)
{
    for (BigInt i = BigInt(2); i * i <= n; i++)
        if (n % i == BigInt(0))
            return false;

    return true;
}

void primeFactorize(BigInt n)
{
    std::cout << n << " = ";
    BigInt limit(n);
    for (BigInt i = BigInt(2); i * i <= limit; i++)
    {
        while (n != i)
            if (n % i == BigInt(0))
            {
                std::cout << i << " * ";
                n /= i;
            }
            else
                break;
    }

    std::cout << n << '\n';
    return;
}

END_BIGINT_MATH