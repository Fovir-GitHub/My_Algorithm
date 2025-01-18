#ifndef _BIGNUMBER_H_
#define _BIGNUMBER_H_

#include <algorithm>
#include <iostream>
#include <string>

class BigInt
{
private:
    std::string number;

public:
    BigInt()
        : number("")
    {
    }

    BigInt(const char * num)
        : number(num)
    {
    }

    BigInt(std::string num)
        : number(num)
    {
    }

    ~BigInt() {}

    void ReverseNumber() { std::reverse(number.begin(), number.end()); }
    int NumberLength() const { return number.length(); }

    const char operator[](int i) const { return number[i]; }
    char operator[](int i) { return number[i]; }

    friend bool operator>(const BigInt & first, const BigInt & second);
    friend bool operator==(const BigInt & first, const BigInt & second);
    friend bool operator<(const BigInt & first, const BigInt & second);

    friend BigInt operator+(BigInt first, BigInt second);

    friend std::ostream & operator<<(std::ostream & os, const BigInt & bi);
    friend std::istream & operator>>(std::istream & is, BigInt & bi);
};

#endif // !_BIGNUMBER_H_