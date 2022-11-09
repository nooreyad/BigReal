#ifndef GROUPTASK1_ASSIGNMENT2_BIGREAL_H
#define GROUPTASK1_ASSIGNMENT2_BIGREAL_H
#include <bits/stdc++.h>
using namespace std;

class BigDecimalInt{
private:
    string number;
    char sign;
    void setNumber(string num);
    bool checkValidInput(string input);

public:
    bool operator < (const BigDecimalInt& anotherDec);
    bool operator > (const BigDecimalInt& anotherDec);
    bool operator == (const BigDecimalInt anotherDec);
    BigDecimalInt& operator = (BigDecimalInt anotherDec);
    BigDecimalInt operator + (BigDecimalInt number2);
    BigDecimalInt operator - (BigDecimalInt anotherDec);
    friend ostream &operator << (ostream &out, BigDecimalInt num);
    int size();
    int Sign();
    void push_back(char ch);
    void push_front(char ch);
    BigDecimalInt(){}
    BigDecimalInt(string num)
    {
        setNumber(num);
    }
    string getnum(){
        return number;
    }
    friend class BigReal;
};


class BigReal {
private:
    string * real = new string;
    BigDecimalInt realNum;
    int point;
    bool realSign;
public:
    BigReal (double realNumber = 0.0); // Default constructor
    BigReal (string realNumber);
    BigReal (BigDecimalInt bigInteger);
    ~BigReal();
    BigReal (const BigReal& other); // Copy constructor
    BigReal (BigReal&& other); // Move constructor
    BigReal& operator= (const BigReal& other); // Assignment operator
    BigReal& operator= (BigReal&& other); // Move assignment
    BigReal operator+ (BigReal& other);
    BigReal operator- (BigReal& other);
    bool operator< (BigReal &anotherReal);
    bool operator> (BigReal &anotherReal);
    bool operator== (BigReal &anotherReal);
    int size();
    int sign();
    friend ostream& operator << (ostream& out, BigReal& num);
    friend istream& operator >> (istream& in, BigReal& num);
};


#endif //GROUPTASK1_ASSIGNMENT2_BIGREAL_H
