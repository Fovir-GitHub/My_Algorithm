#ifndef _BIGINT_H_
#define _BIGINT_H_

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>

class BigInt
{
private:
    std::string number;

public:
    BigInt() : number("0") {}
    BigInt(std::string s);
    explicit BigInt(int num);
    operator std::string() const { return number; }

    bool IsNegative() const { return number.length() > 0 && number[0] == '-'; }
    const int Length() const { return number.length(); }

    const char operator[](int i) const { return number[i]; }
    char operator[](int i) { return number[i]; }

    BigInt operator-() const;
    BigInt abs() const;

    friend std::ostream & operator<<(std::ostream & os, const BigInt & bi);
    friend std::istream & operator>>(std::istream & is, BigInt & bi);

    friend bool operator>(const BigInt & first, const BigInt & second);
    friend bool operator==(const BigInt & first, const BigInt & second);
    friend bool operator<(const BigInt & first, const BigInt & second);

    friend BigInt operator+(const BigInt & fn, const BigInt & sn);
    BigInt & operator+=(const BigInt & other);
    friend BigInt operator-(const BigInt & fn, const BigInt & sn);
    friend BigInt operator*(const BigInt & num, const int & digit);
    friend BigInt operator*(const int & digt, const BigInt & num);
    friend BigInt operator*(const BigInt & fn, const BigInt & sn);
};

#endif // !_BIGINT_H_