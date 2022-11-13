#include "BigReal.h"
#include<bits/stdc++.h>
// regex function that checks the validation of the input.
bool BigDecimalInt :: checkValidInput(string input)
{
    regex validInput("[-+]?[0-9]+");
    return regex_match(input, validInput);
}

// constructor that takes a string as an input.
void BigDecimalInt :: setNumber(string num)
{
    bool validNumber = checkValidInput(num);
    if(validNumber)
    {
        number = num;
        if(number[0] == '+')
        {
            number.erase(0,1);
            sign = '+';
        }
        else if (number[0] == '-')
        {
            number.erase(0,1);
            sign = '-';
        }
        else
        {
            sign = '+';
        }
    }
    else
    {
        cout << "Invalid" << "\n";
        exit(1);
    }
}

// operator < overloading function.
bool BigDecimalInt :: operator < (const BigDecimalInt& anotherDec)
{
    string comp1 = "", comp2 = "";
    long long len1 = number.length(), len2 = anotherDec.number.length();

    while (len1 < len2){
        comp1 += '0';
        len1++;
    }
    while (len2 < len1){
        comp2 += '0';
        len2++;
    }
    comp1 += number;
    comp2 += anotherDec.number;

    if(sign == '-' && anotherDec.sign == '+')
    {
        return true;
    }
    else if(sign == '+' && anotherDec.sign == '-')
    {
        return false;
    }
    else if(sign == '+' && anotherDec.sign == '+')
    {
        return comp1 < comp2;
    }
    else
    {
        return comp1 > comp2;
    }
}

// operator > overloading function.
bool BigDecimalInt :: operator > (const BigDecimalInt &anotherDec)
{
    string comp1 = "", comp2 = "";
    long long len1 = number.length(), len2 = anotherDec.number.length();

    while (len1 < len2){
        comp1 += '0';
        len1++;
    }
    while (len2 < len1){
        comp2 += '0';
        len2++;
    }
    comp1 += number;
    comp2 += anotherDec.number;

    if(sign == '-' && anotherDec.sign == '+')
    {
        return false;
    }
    else if(sign == '+' && anotherDec.sign == '-')
    {
        return true;
    }
    else if(sign == '+' && anotherDec.sign == '+')
    {
        return comp1 > comp2;
    }
    else
    {
        return comp1 < comp2;
    }
}

// operator == overloading function.
bool BigDecimalInt :: operator == (const BigDecimalInt anotherDec)
{
    if (sign == anotherDec.sign && number == anotherDec.number)
    {
        return true;

    }
    else
    {
        return false;
    }
}

// operator = overloading function.
BigDecimalInt& BigDecimalInt :: operator = (BigDecimalInt anotherDec)
{
    sign = anotherDec.sign;
    number = anotherDec.number;
    return *this;
}

//addition implementation.
string addition(string num1,string num2)
{
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    string res = "";
    int carry = 0;
    while (it1 != num1.rend())
    {
        int twoDigitsSum;
        carry = 0;
        twoDigitsSum = ((*it1 - '0') + (*it2 - '0'));
        if (twoDigitsSum >= 10)
        {
            carry = 1;
        }
        res = char((twoDigitsSum % 10) + '0') + res;
        *(it1 + 1) = char(((*(it1 + 1) - '0') + carry) + '0');
        it1++;
        it2++;
    }
    if (carry)
    {
        res = char((carry) + '0') + res;
    }
    return res;
}

//subtraction implementation
string subtraction(string num1,string num2){
    deque<long long>d;
    string res;

    for (long long i = num1.length() - 1; i >= 0; i--)
    {
        if (num1[i] < num2[i])
        {
            num1[i] = char (((num1[i] - '0') + 10) + '0');
            num1[i - 1] = char (((num1[i - 1] - '0') - 1) + '0');
            d.push_front((num1[i] - '0') - (num2[i] - '0'));
        }
        else
        {
            d.push_front((num1[i] - '0') - (num2[i] - '0'));
        }
    }

    for (auto i : d)
    {
        res += to_string(i);
    }
    return res;
}

// // operator + overloading function.
BigDecimalInt BigDecimalInt :: operator + (BigDecimalInt number2)
{
    BigDecimalInt result;
    char signNumber1 = sign, signNumber2 = number2.sign;
    string num1 = number, num2 = number2.number;
    BigDecimalInt number1 = *this;

    while (num1.length() < num2.length()){
        num1 = '0' + num1;
    }
    while (num2.length() < num1.length()){
        num2 = '0' + num2;
    }

    if (signNumber1 == signNumber2){
        result.sign = signNumber1;
        result.number = addition(num1,num2);

    }else{

        if(number1.sign=='-')
        {
            number1.sign = '+';
            result = (number2-number1);
        }
        else{
            number2.sign = '+';
            result = (number1-number2);
        }
    }
    return result;
}

// operator - overloading function.
BigDecimalInt BigDecimalInt :: operator - (BigDecimalInt anotherDec)
{
    BigDecimalInt obj;
    deque<long long> d;
    string strmin = "", res = "";
    string num1 = number, num2 = anotherDec.number;
    char sign1 = sign, sign2 = anotherDec.sign;

    if (number.length() > anotherDec.number.length())
    {
        for (long long i = 0; i < number.length() - anotherDec.number.length(); i++)
        {
            strmin += '0';
        }
        strmin += anotherDec.number;
        num2 = strmin;
    }
    else if (number.length() < anotherDec.number.length())
    {
        for (long long i = 0; i < anotherDec.number.length() - number.length(); i++)
        {
            strmin += '0';
        }
        strmin += number;
        num1 = strmin;
    }

    bool ok = false, is_determined = false;
    if (num1 < num2)
    {
        swap(num1, num2);
        swap(sign1, sign2);
        ok = true;
    }

    if (sign1 == sign2 )
    {
        res = subtraction(num1,num2);

        if(sign1=='-')ok = !ok;
    }
    else
    {
        res = addition(num1,num2);
        if(sign == '-')
        {
            obj.sign = '-';
            is_determined = true;
        }
        else
        {
            obj.sign = '+';
            is_determined = true;
        }

    }

    bool right = false;
    for (long long i = 0; i < res.length(); i++)
    {
        if (res[i] != '-' && res[i] != '0')
        {
            right = true;
        }
        if (!right && res[i] == '0')
        {
            res.erase(i, 1);
            i--;
        }
    }

    if(res.empty()) res = "0";
    if (!is_determined && (ok))
    {
        obj.sign = '-';
    }
    else if(!is_determined)
    {
        obj.sign = '+';
    }

    obj.number=res;
    return obj;
}

// function to return the size of number.
int BigDecimalInt :: size()
{
    return number.size();
}

// function returns the sign.
int BigDecimalInt :: Sign()
{
    if (sign == '+')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// function to push a character.
void BigDecimalInt ::push_back(char ch)
{
    number.push_back(ch);
}

// function to push a character in the front.
void BigDecimalInt ::push_front(char ch)
{
    string temp;
    temp = ch + number;
    number = temp;
}

// operator << overloading function.
ostream &operator << (ostream &out, BigDecimalInt num)
{
    if(num.sign == '+')
    {
        out << num.number ;
    }
    else
    {
        if(num.number == "0")
        {
            out << num.number ;
        }
        else
        {
            out << num.sign << num.number ;
        }
    }
    return out;
}
// ---------------------------------------------------------------------------------------------------------------
// ---------------------------------------- BigReal Implementation -----------------------------------------------
// ---------------------------------------------------------------------------------------------------------------


// ---------------------------------------- Nour Mohamed - 20210428 -----------------------------------------------

BigReal::BigReal(double realNumber) {
    if(realNumber < 0){
        realNumber *= -1;
        *real = to_string(realNumber);
        realSign = true;
    }else{
        *real = to_string(realNumber);
        realSign = false;
    }
    for (int i = 0; i < (*real).size() ; ++i) {  // 100.45
        if ((*real)[i] == '.') {
            (*real).erase(i, 1);
            point = i;
        }
    }
    for (int i = (*real).size()-1; i >= point; --i) {
        if((*real)[i] == '0'){
            (*real).erase(i,1);
        } else {
            break;
        }
    }
}

BigReal::BigReal(string realNumber){
    int cnt = (count(realNumber.begin(), realNumber.end(), '.'));
    if (cnt > 1) {
        cout << realNumber << endl << "This input doesn't represent a valid format for a real number." << endl;
        cout << "Please, enter the number with only one decimal point." << endl;
    }
    else {
        if(realNumber[0] == '-'){
            realNumber.erase(0,1);
            realSign = true;
        } else if(realNumber[0] == '+'){
            realNumber.erase(0,1);
            realSign = false;
        } else {
            realSign = false;
        }
        *real = realNumber;
        for (int i = 0; i < realNumber.size(); ++i) {
            if (realNumber[i] == '.') {
                (*real).erase(i, 1);
                point = i;
            }
        }
        for (int i = (*real).size()-1; i >= point; --i) {
            if((*real)[i] == '0'){
                (*real).erase(i,1);
            } else {
                break;
            }
        }
    }
}

BigReal::BigReal(BigDecimalInt bigInteger) {
    (*real) = bigInteger.number;
    if(bigInteger.sign == '+')
        realSign = false;
    else
        realSign = true;
    point = bigInteger.number.size();
    realNum.number = bigInteger.number;
    if(bigInteger.sign == '+')
        realNum.sign = false;
    else
        realNum.sign = true;
}

BigReal::BigReal(const BigReal &other){
    cout<<"Copy constructor"<<endl;
    *real = *other.real;
    point = other.point;
    realSign = other.realSign;
}

BigReal::BigReal(BigReal &&other) {
    cout<<"Move constructor"<<endl;
    *real = *other.real;
    point = other.point;
    realSign = other.realSign;
    other.real = nullptr;
    other.point = 0;
    realSign = false;
}
BigReal::~BigReal() {
    delete real;
}

BigReal& BigReal:: operator=(const BigReal &other) {
    cout<<"Copy assignment operator"<<endl;
    *(this->real) = *other.real;
    point = other.point;
    realSign = other.realSign;
    return *this;
}

BigReal& BigReal::operator=(BigReal &&other) {
    cout<<"Move assignment operator"<<endl;
    *(this->real) = *other.real;
    point = other.point;
    realSign = other.realSign;
    other.real= nullptr;
    return *this;
}

// ---------------------------------------- Noor Eyad - 20210499 -----------------------------------------------

BigReal BigReal::operator+(BigReal &other) {
    BigDecimalInt temp;
    BigDecimalInt num1;
    BigDecimalInt num2;
    BigReal result;
    if(this->size()-this->point < other.size()-other.point){ // 1.23    1.654
        int diff = (other.size()-other.point) - (this->size()-this->point);
        for (int i = 0; i < diff; ++i) {
            *(this->real) += '0';
        }
    } else if(this->size()-this->point > other.size()-other.point){  // 1.236    1.65
        int diff = (this->size()-this->point) - (other.size()-other.point);
        for (int i = 0; i < diff; ++i) {
            *(other.real) += '0';
        }
    }
    int tempPoint = 0;
    if(this->point < other.point){      // 1.2   22.2
        tempPoint = this->point;
        int diff = other.point - this->point;
        for (int i = 0; i < diff; ++i) {
            *(this->real) = '0' + *(this->real);
            tempPoint++;
        }
    } else if(this->point > other.point){      // 177.2   22.2
        tempPoint = other.point;
        int diff = this->point - other.point;
        for (int i = 0; i < diff; ++i) {
            *(other.real) = '0' + *(other.real);
            tempPoint++;
        }
    } else {
        tempPoint = this->point;
    }
    num1.number = *(this->real);
    if(this->realSign)
        num1.sign = '-';
    else
        num1.sign = '+';
    num2.number = *(other.real);
    if(other.realSign)
        num2.sign = '-';
    else
        num2.sign = '+';
    temp = num1.operator+(num2);
    *(result.real) = temp.number;
    if(temp.Sign() == 0)
        result.realSign = true;
    else
        result.realSign = false;
    result.point = tempPoint;
    return result;
}

BigReal BigReal::operator-(BigReal &other) {
    BigDecimalInt temp;
    BigDecimalInt num1;
    BigDecimalInt num2;
    BigReal result;
    bool isZero = true;
    bool borrow = false;
    string temp1Before, temp2Before, temp1After, temp2After;
    if(this->size()-this->point < other.size()-other.point){ // 1.23    1.654
        int diff = (other.size()-other.point) - (this->size()-this->point);
        for (int i = 0; i < diff; ++i) {
            *(this->real) += '0';
        }
    } else if(this->size()-this->point > other.size()-other.point){  // 1.236    1.65
        int diff = (this->size()-this->point) - (other.size()-other.point);
        for (int i = 0; i < diff; ++i) {
            *(other.real) += '0';
        }
    }
    int tempPoint;
    if(this->point < other.point){      // 1.2   22.2
        tempPoint = this->point;
        int diff = other.point - this->point;
        for (int i = 0; i < diff; ++i) {
            *(this->real) = '0' + *(this->real);
            tempPoint++;
        }
    } else if(this->point > other.point){      // 177.2   22.2
        tempPoint = other.point;
        int diff = this->point - other.point;
        for (int i = 0; i < diff; ++i) {
            *(other.real) = '0' + *(other.real);
            tempPoint++;
        }
    } else {
        tempPoint = this->point;
    }
    for (int i = 0; i < this->point; ++i) {
        if((*real)[i] != '0'){
            isZero = false;
            break;
        }
    }
    temp1Before = (*real).substr(0,this->point);
    temp1After = (*real).substr(this->point);
    temp2Before = (*other.real).substr(0,other.point);
    temp2After = (*other.real).substr(other.point);
    if((temp1Before < temp2Before || temp1After < temp2After || temp1Before == temp2Before) && temp1Before != "0" && this->point != 0 && other.point != 0){
        cout << "borroooowww" << endl;
        borrow = true;
    }
    num1.number = *(this->real);
    if(this->realSign)
        num1.sign = '-';
    else
        num1.sign = '+';
    num2.number = *(other.real);
    if(other.realSign)
        num2.sign = '-';
    else
        num2.sign = '+';
    temp = num1.operator-(num2);
    *(result.real) = temp.number;
    if(temp.Sign() == 0)
        result.realSign = true;
    else
        result.realSign = false;
    result.point = tempPoint;
    if(this->point == 0 || other.point == 0){
        isZero = false;
        cout << "inside the point 0 if conditional " << endl;
        *(result.real) = '0' + *(result.real);
        result.point = 1;
    }
    if(isZero){
        cout << " iszero " << endl;
        *(result.real) = '0' + *(result.real);
    }
    if(borrow){
        cout << " borrow " << endl;
        if(other.point == 1){
            *(result.real) = '0' + *(result.real);
        } else if(temp1Before == temp2Before){
            *(result.real) = '0' + *(result.real);
            result.point--;
        } else {
            result.point--;
        }
    }
    return result;
}

// ---------------------------------------- Merna Islam - 20210500 -----------------------------------------------

bool BigReal::operator<(BigReal &anotherReal) {
    if(this->operator==(anotherReal)){
        return false;
    }
    if(this->realSign && !anotherReal.realSign){                              // -ve      +ve
        return true;
    } else if(!this->realSign && anotherReal.realSign){                       // +ve      -ve
        return false;
    } else if(this->point < anotherReal.point && !this->realSign){            // 1.1        10.1
        return true;
    } else if(this->point < anotherReal.point && this->realSign){             // -1.1      -10.1
        return false;
    } else if(this->point > anotherReal.point && !this->realSign){             // 10.1       1.1
        return false;
    } else if(this->point > anotherReal.point && this->realSign){             // -10.1     -1.1
        return true;
    } else if(this->size() > anotherReal.size() && !this->realSign){          // 10.99      10.9
        return false;
    } else if(this->size() > anotherReal.size() && this->realSign){           // -10.99    -10.9
        return true;
    } else if(this->size() < anotherReal.size() && !this->realSign){          // 10.9       10.99
        return true;
    } else if(this->size() < anotherReal.size() && this->realSign){           // -10.9     -10.99
        return false;
    } else if(!this->realSign){
        for (int i = 0; i < this->size(); ++i) {
            if (this->real[i] < anotherReal.real[i]) {
                return true;
            } else if (this->real[i] > anotherReal.real[i]) {
                return false;
            }
        }
    } else {
        for (int i = 0; i < this->size(); ++i) {
            if (this->real[i] > anotherReal.real[i]) {
                return true;
            } else if (this->real[i] < anotherReal.real[i]) {
                return false;
            }
        }
    }
    return false;
}

bool BigReal::operator>(BigReal &anotherReal) {
    bool result = this->operator<(anotherReal);
    if(result){
        return false;
    } else {
        return true;
    }
}

bool BigReal::operator==(BigReal &anotherReal) {
    if(this->point != anotherReal.point || this->realSign != anotherReal.realSign || this->size() != anotherReal.size()){
        return false;
    } else if(*(this->real) != *(anotherReal.real)){
            return false;
    }
    return true;
}

int BigReal::size() {
    int count = 0;
    for (auto item: *real) {
        count++;
    }
    return count;
}

int BigReal::sign() {
    if(realSign){
        return 1;
    }
    else{
        return 0;
    }
}

ostream& operator << (ostream& out, BigReal& num){
    if(num.realSign){
        out << '-';
    }
    string temp = ".";
    string temp2 = *(num.real);
    temp2.insert(num.point, temp);
    out << temp2 << endl;
    return out;
}

istream& operator >> (istream& in, BigReal& num) {  // in >> num
    string temp;
    in >> temp;
    num = BigReal (temp);
    return in;
}
