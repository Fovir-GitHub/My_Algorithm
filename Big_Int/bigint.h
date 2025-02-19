#ifndef _BIGINT_H_
#define _BIGINT_H_

#include <iostream>
#include <string>

class BigInt
{
private:
    std::string number;

public:
    BigInt() : number("0") {}
    BigInt(std::string & s);
    BigInt(int num);

    bool is_negative() const { return number.length() > 0 && number[0] == '-'; }

    const char operator[](int i) const { return number[i]; }
    char operator[](int i) { return number[i]; }

    friend std::ostream & operator<<(std::ostream & os, const BigInt & bi);
    friend std::istream & operator>>(std::istream & is, BigInt & bi);

    friend bool operator>(BigInt & first, BigInt & second);
    friend bool operator==(BigInt & first, BigInt & second);
    friend bool operator<(BigInt & first, BigInt & second);
};

#endif // !_BIGINT_H_