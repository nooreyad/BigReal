#ifndef GROUPTASK1_ASSIGNMENT2_BIGREAL_H
#define GROUPTASK1_ASSIGNMENT2_BIGREAL_H
#include <bits/stdc++.h>
using namespace std;

class BigDecimalInt {
private:
    string num;
    bool Sign;
public:
    BigDecimalInt();
    BigDecimalInt(string decStr);
    BigDecimalInt(int decInt);
    BigDecimalInt operator+(BigDecimalInt &anotherDec);
    BigDecimalInt summation(BigDecimalInt &anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    bool operator< (BigDecimalInt anotherDec);
    bool operator> (BigDecimalInt anotherDec);
    bool operator==(BigDecimalInt &anotherDec);
    BigDecimalInt& operator= (const BigDecimalInt& anotherDec);
    int size();
    int sign();
    friend ostream& operator << (ostream& out, BigDecimalInt& b);
    friend class BigReal;
};

class BigReal {
private:
    string * real = new string;
    BigDecimalInt realNum;
    int point;
    bool realSign;
public:
    BigReal(){}
    BigReal (double realNumber = 0.0); // Default constructor
    BigReal (string realNumber);
    BigReal (BigDecimalInt bigInteger);
    ~BigReal();
    BigReal (const BigReal& other); // Copy constructor
    BigReal (BigReal&& other); // Move constructor
    BigReal& operator= (BigReal& other); // Assignment operator
    BigReal& operator= (BigReal&& other); // Move assignment
    BigReal operator+ (BigReal& other);
    BigReal operator- (BigReal& other);
    bool operator< (BigReal anotherReal);
    bool operator> (BigReal anotherReal);
    bool operator== (BigReal anotherReal);
    int size();
    int sign();
    friend ostream& operator << (ostream& out, BigReal& num);
    friend istream& operator >> (istream& out, BigReal& num);
};


#endif //GROUPTASK1_ASSIGNMENT2_BIGREAL_H
