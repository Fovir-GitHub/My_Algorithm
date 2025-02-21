#include "bigint.h"
#include <algorithm>
#include <cctype>
#include <cmath>

static void PreProcessString(std::string & first, std::string & second);
static int Char2Digit(const char & ch);
static char Digit2Char(const int & digit);

BigInt::BigInt(std::string s)
{
    if (*s.begin() != '-' && !std::isdigit(*s.begin()))
    {
        number = "0";
        return;
    }

    int is_negative = static_cast<int>(*s.begin() == '-');

    for (auto iter = (is_negative ? s.begin() + 1 : s.begin()); iter != s.end();
         iter++)
        if (!std::isdigit(*iter))
        {
            number = "0";
            return;
        }

    s.erase(is_negative,
            std::min(s.find_first_not_of('0', is_negative) - is_negative,
                     s.size() - 1));

    if (s.size() < 1 || (s.size() == 1 && s[0] == '-'))
    {
        number = "0";
        return;
    }

    number = s;
}

BigInt::BigInt(int num)
{
    if (num == 0)
    {
        number = "0";
        return;
    }
    number = "";
    bool IsNegative = num < 0;
    num = std::abs(num);

    while (num)
    {
        number.insert(number.begin(), num % 10 + '0');
        num /= 10;
    }

    if (IsNegative)
        number.insert(number.begin(), '-');
}

BigInt BigInt::operator-() const
{
    BigInt temp = *this;

    if (temp.IsNegative())
        temp.number.erase(temp.number.begin());
    else
        temp.number.insert(temp.number.begin(), '-');

    return temp;
}

BigInt BigInt::abs() const
{
    if (*this < BigInt(0))
        return this->operator-();
    else
        return *this;
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

bool operator>(const BigInt & first, const BigInt & second)
{
    if (first.IsNegative() ^ second.IsNegative())
        return !first.IsNegative();

    int first_length = first.Length(), second_length = second.Length();

    if (first_length != second_length)
        return (first.IsNegative() ? first_length < second_length
                                   : first_length > second_length);

    for (int i = (first.IsNegative() ? 1 : 0); i < first_length; i++)
        if (first[i] != second[i])
            return (first.IsNegative() ? first[i] < second[i]
                                       : first[i] > second[i]);

    return false;
}

bool operator==(const BigInt & first, const BigInt & second)
{
    return first.number == second.number;
}

bool operator<(const BigInt & first, const BigInt & second)
{
    return !(first > second || first == second);
}

BigInt operator+(const BigInt & fn, const BigInt & sn)
{
    if (fn.IsNegative() ^ sn.IsNegative())
        return (fn.IsNegative() ? sn - (-fn) : fn - (-sn));

    std::string first = fn.abs(), second = sn.abs(), result("");

    PreProcessString(first, second);

    int next = 0;
    for (int i = 0; i < first.length(); i++)
    {
        int digit = (Char2Digit(first[i]) + Char2Digit(second[i]) + next);
        next = digit / 10;
        digit %= 10;
        result += Digit2Char(digit);
    }

    if (next)
        result += Digit2Char(next);

    std::reverse(result.begin(), result.end());
    if (fn.IsNegative())
        result.insert(result.begin(), '-');

    return result;
}

BigInt operator-(const BigInt & fn, const BigInt & sn)
{
    if (fn == sn)
        return 0;

    if (!fn.IsNegative() && sn.IsNegative())
        return fn + (-sn);

    if (fn.IsNegative() && !sn.IsNegative())
        return -((-fn) + (-sn));

    /*
    - -
    + +
    */

    bool result_is_negative = (fn < sn);

    std::string first = std::max(fn.abs(), sn.abs()),
                second = std::min(fn.abs(), sn.abs()), result("");

    PreProcessString(first, second);

    int borrow = 0;
    for (int i = 0; i < first.length(); i++)
    {
        int first_number = Char2Digit(first[i]) - borrow,
            second_number = Char2Digit(second[i]);
        if (first_number < second_number)
        {
            borrow = 1;
            first_number += 10;
        }
        else
            borrow = 0;

        result += Digit2Char(first_number - second_number);
    }

    result.erase(result.find_last_not_of('0') + 1);
    std::reverse(result.begin(), result.end());
    if (result_is_negative)
        result.insert(result.begin(), '-');

    return result;
}

void PreProcessString(std::string & first, std::string & second)
{
    std::reverse(first.begin(), first.end());
    std::reverse(second.begin(), second.end());

    (first.length() < second.length() ? first : second)
        .append((first.length() < second.length()
                     ? second.length() - first.length()
                     : first.length() - second.length()),
                '0');

    return;
}

int Char2Digit(const char & ch)
{
    return std::isdigit(ch) ? ch - '0' : ch;
}

char Digit2Char(const int & digit)
{
    return digit + '0';
}
