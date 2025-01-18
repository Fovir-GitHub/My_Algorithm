#include "bignumber.h"
#include <cctype>
#include <cmath>

bool operator>(const BigInt & first, const BigInt & second)
{
    int first_length = first.NumberLength(),
        second_length = second.NumberLength();

    if (first_length > second_length)
        return true;
    else if (first_length < second_length || first == second)
        return false;

    for (int i = 0; i < first_length; i++)
        if (first[i] != second[i])
            return first[i] > second[i];

    return false;
}

bool operator==(const BigInt & first, const BigInt & second)
{
    return first.number == second.number;
}

bool operator<(const BigInt & first, const BigInt & second)
{
    return !(first > second) && !(first == second);
}

BigInt operator+(BigInt first, BigInt second)
{
    using std::string;

    string result("");

    int first_length = first.NumberLength(),
        second_length = second.NumberLength();

    first.ReverseNumber();
    second.ReverseNumber();
    (first_length > second_length ? second : first)
        .number.append(std::abs(first_length - second_length), '0');

    int next_plus = 0;
    for (int i = 0; i < first.NumberLength(); i++)
    {
        int temp = first[i] + second[i] - '0' - '0' + next_plus;
        next_plus = temp / 10;
        result += (temp % 10 + '0');
    }

    if (next_plus)
        result += '1';

    std::reverse(result.begin(), result.end());

    return BigInt(result);
}

std::ostream & operator<<(std::ostream & os, const BigInt & bi)
{
    os << bi.number;
    return os;
}

std::istream & operator>>(std::istream & is, BigInt & bi)
{
    is >> bi.number;

    return is;
}
