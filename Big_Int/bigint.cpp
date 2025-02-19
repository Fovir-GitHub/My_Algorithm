#include "bigint.h"
#include <cctype>
#include <cmath>

BigInt::BigInt(std::string & s) : number(s)
{
}

BigInt::BigInt(int num)
{
    number = "";
    bool is_negative = num < 0;
    num = std::abs(num);

    while (num)
    {
        number.insert(number.begin(), num % 10 + '0');
        num /= 10;
    }

    if (is_negative)
        number.insert(number.begin(), '-');
}

std::ostream & operator<<(std::ostream & os, const BigInt & bi)
{
    os << bi.number;
    return os;
}

std::istream & operator>>(std::istream & is, BigInt & bi)
{
    std::string temp("");
    is >> temp;
    bi = BigInt(temp);

    return is;
}

bool operator>(BigInt & first, BigInt & second)
{
    if (first.is_negative() ^ second.is_negative())
        return !first.is_negative();

    int first_length = first.number.length(),
        second_length = second.number.length();

    if (first_length != second_length)
        return (first.is_negative() ? first_length < second_length
                                    : first_length > second_length);

    for (int i = (first.is_negative() ? 1 : 0); i < first_length; i++)
        if (first[i] != second[i])
            return (first.is_negative() ? first[i] < second[i]
                                        : first[i] > second[i]);

    return false;
}

bool operator==(BigInt & first, BigInt & second)
{
    return first.number == second.number;
}

bool operator<(BigInt & first, BigInt & second)
{
    return !(first > second || first == second);
}
