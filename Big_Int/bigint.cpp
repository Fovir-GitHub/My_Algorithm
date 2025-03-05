#include "bigint.h"
#include <algorithm>
#include <cctype>
#include <cmath>

static void PreProcessString(std::string & first, std::string & second);
static int  Char2Digit(const char & ch);
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
    number          = "";
    bool IsNegative = num < 0;
    num             = std::abs(num);

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

BigInt & BigInt::operator+=(const BigInt & other)
{
    return (*this = *this + other);
}

BigInt & BigInt::operator-=(const BigInt & other)
{
    return (*this = *this - other);
}

BigInt & BigInt::operator*=(const BigInt & other)
{
    return (*this = *this * other);
}

BigInt & BigInt::operator/=(const BigInt & other)
{
    return (*this = *this / other);
}

BigInt & BigInt::operator++()
{
    return (*this += BigInt(1));
}

BigInt BigInt::operator++(int)
{
    BigInt temp = *this;
    *this += BigInt(1);

    return temp;
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

BigInt operator*(const BigInt & num, const int & digit)
{
    if (digit == 0)
        return static_cast<BigInt>(0);

    std::string result(""), s = num;
    int         next = 0;

    for (auto iter = s.rbegin(); iter != s.rend(); iter++)
    {
        if (!std::isdigit(*iter))
            break;

        int temp = (Char2Digit(*iter) * digit + next);
        next     = temp / 10;
        temp %= 10;
        result.insert(result.begin(), Digit2Char(temp));
    }

    if (next)
        result.insert(result.begin(), Digit2Char(next));

    if (num.IsNegative())
        result.insert(result.begin(), '-');

    return result;
}

BigInt operator*(const int & digit, const BigInt & num)
{
    return num * digit;
}

BigInt operator*(BigInt fn, BigInt sn)
{
    if (fn == BigInt(0) || sn == BigInt(0))
        return BigInt(0);

    bool   result_is_negative = (fn.IsNegative() ^ sn.IsNegative());
    BigInt result("0");
    fn = fn.abs();
    sn = sn.abs();

    for (int i = sn.Length() - 1; i >= 0; i--)
    {
        BigInt temp = fn * Char2Digit(sn[i]);
        temp.number.append(sn.Length() - 1 - i, '0');
        result += temp;
    }

    return (result_is_negative ? -result : result);
}

BigInt operator/(BigInt fn, BigInt sn)
{
    // if (sn == BigInt(0) || fn == BigInt(0))
    //     return BigInt(0);

    // bool result_is_negative = (fn.IsNegative() ^ sn.IsNegative());
    // fn = fn.abs(), sn = sn.abs();

    // if (fn < sn)
    //     return BigInt(0);
    // if (fn == sn)
    //     return BigInt(1);
    return Divide(fn, sn).first;
}

std::pair<BigInt, BigInt> Divide(BigInt fn, BigInt sn)
{
    if (sn == BigInt(0) || fn == BigInt(0))
        return std::pair<BigInt, BigInt>(BigInt(0), BigInt(0));
    if (fn.abs() < sn.abs())
        return std::pair<BigInt, BigInt>(BigInt(0), fn);
    if (fn == sn)
        return std::pair<BigInt, BigInt>(BigInt(1), BigInt(0));

    bool result_is_negative = (fn.IsNegative() ^ sn.IsNegative());
    fn = fn.abs(), sn = sn.abs();

    std::string quotient(""), remainder("");
    BigInt      to_divide;

    for (int i = 0; i < fn.Length(); i++)
    {
        to_divide = to_divide * BigInt(10) + BigInt(Char2Digit(fn[i]));
        if (to_divide < sn)
        {
            quotient += Digit2Char(0);
            continue;
        }

        for (int j = 0; j <= 9; j++)
        {
            if ((remainder = (to_divide - (sn * BigInt(j)))) < sn)
            {
                quotient += Digit2Char(j);
                to_divide = remainder;
                break;
            }
        }
    }

    BigInt final_remainder(remainder);

    if (result_is_negative)
    {
        quotient.insert(quotient.begin(), '-');
        remainder.insert(remainder.begin(), '-');

        final_remainder = BigInt(remainder);
        while (final_remainder < BigInt(0)) final_remainder += sn;
    }

    return std::pair<BigInt, BigInt>(quotient, final_remainder);
}

BigInt operator%(BigInt fn, BigInt sn)
{
    return Divide(fn, sn).second;
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

bool operator>=(const BigInt & fn, const BigInt & sn)
{
    return (fn > sn || fn == sn);
}

bool operator<=(const BigInt & fn, const BigInt & sn)
{
    return (fn < sn || fn == sn);
}

bool operator!=(const BigInt & fn, const BigInt & sn)
{
    return !(fn == sn);
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
        next      = digit / 10;
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
        return BigInt(0);

    if (!fn.IsNegative() && sn.IsNegative())
        return fn + (-sn);

    if (fn.IsNegative() && !sn.IsNegative())
        return -((-fn) + (-sn));

    bool result_is_negative = (fn < sn);

    std::string first  = std::max(fn.abs(), sn.abs()),
                second = std::min(fn.abs(), sn.abs()), result("");

    PreProcessString(first, second);

    int borrow = 0;
    for (int i = 0; i < first.length(); i++)
    {
        int first_number  = Char2Digit(first[i]) - borrow,
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
