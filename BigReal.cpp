#include "BigReal.h"
#include<bits/stdc++.h>
using namespace std;
char a = ' ';

BigDecimalInt BigDecimalInt::summation(BigDecimalInt &anotherDec){
    BigDecimalInt result;
    char to_char;
    int digit1, digit2, sum ,carry = 0;
    for(int i = anotherDec.size()-1; i >= 0; i--){
        digit1 = anotherDec.num[i] - 48;
        digit2 = this->num[i] - 48;
        sum = digit1 + digit2 + carry;
        if(sum < 10){
            carry = 0;
            to_char = sum + 48;
            result.num = to_char + result.num;
        } else {
            to_char = sum%10 + 48;
            result.num = to_char + result.num;
            carry = sum/10;
        }
    }
    if(carry != 0){
        to_char = carry + 48;
        result.num = to_char + result.num;
    }
    if(this->Sign){
        result.Sign = true;
    }
    return result;
}


BigDecimalInt::BigDecimalInt() {
    Sign = false;
    num = "";
}

BigDecimalInt::BigDecimalInt(int decInt) {
    if(decInt < 0){
        decInt *= -1;
        Sign = true;
        num = to_string(decInt);
    }
    else {
        Sign = false;
        num = to_string(decInt);
    }
}

BigDecimalInt::BigDecimalInt(string decStr) {
    if (decStr[1] == '+' || decStr[1] == '-') {
        cout << decStr << "\n" << "This input doesn't represent a valid format for the number\nPlease enter the number with only one sign\n";
    }
    if (decStr.find(a) != string::npos) {
        cout << decStr << "\n" << "This input doesn't represent a valid format for the number\nPlease enter the number without spaces\n";
    }
    if (decStr[0] == '-') {
        Sign = true;
        for (int i = 1; i < decStr.size(); i++) {
            num.push_back(decStr[i]);
        }
    }
    else if(decStr[0] == '+'){
        Sign = false;
        for (int i = 1; i < decStr.size(); i++) {
            num.push_back(decStr[i]);
        }
    }
    else {
        Sign = false;
        num = decStr;
    }
}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt &anotherDec) {
    BigDecimalInt result;
    if(this->size() > anotherDec.size()){
        int diff = this->size() - anotherDec.size();
        for (int i = 0; i < diff; ++i) {
            anotherDec.num = '0' + anotherDec.num;
        }
    } else if(this->size() < anotherDec.size()){
        int diff = anotherDec.size() - this->size();
        for (int i = 0; i < diff; ++i) {
            this->num = '0' +  this->num;
        }
    }
    if(this->Sign == anotherDec.Sign){
        return summation(anotherDec);
    }
    else if(this->operator>(anotherDec)){
        BigDecimalInt changeSign2 = anotherDec;
        changeSign2.Sign = false;
        return this->operator-(changeSign2);
    } else {
        BigDecimalInt changeSign3 = *this;  // negative + positive == negative - negative
        changeSign3.Sign = false;
        return anotherDec.operator-(changeSign3);
    }
}

BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec){      // 100000 000098
    BigDecimalInt result , temp = *this;
    if(this->operator==(anotherDec)){
        result.num = '0';
        return result;
    }
    int digit1, digit2, subtraction;
    bool remove = false;
    char to_char;
    if(this->size() > anotherDec.size()){
        int diff = this->size() - anotherDec.size();
        for (int i = 0; i < diff; ++i) {
            anotherDec.num = '0' + anotherDec.num;
        }
    } else if(this->size() < anotherDec.size()){
        int diff = anotherDec.size() - this->size();
        for (int i = 0; i < diff; ++i) {
            this->num = '0' +  this->num;
        }
    }
    if (this->Sign == anotherDec.Sign){
        if (this->Sign == 0){
            for(int i = anotherDec.size()-1; i >= 0; i--){
                if(remove){
                    this->num[i]--;
                }
                digit1 = this->num[i] - 48;
                digit2 = anotherDec.num[i] - 48;
                if (digit1 < digit2){
                    remove = true;
                    digit1 += 10;
                    subtraction = digit1 - digit2;
                    to_char = subtraction + 48;
                    result.num = to_char + result.num;
                } else {
                    remove = false;
                    subtraction = digit1 - digit2;
                    to_char = subtraction + 48;
                    result.num = to_char + result.num;
                }
            }
            *this = temp;
            if(this->operator>(anotherDec)){
                return result;
            } else {
                BigDecimalInt answer = anotherDec.operator-(*this);
                answer.Sign = true;
                return answer;
            }
        } else if (this->Sign == 1){            // -999 - -1000 = 999 - 1000
            BigDecimalInt changeSign4 = *this;
            BigDecimalInt changeSign3 = anotherDec;
            changeSign4.Sign = false;
            changeSign3.Sign = false;
            if(changeSign3.operator>(changeSign4)){
                return changeSign3.operator-(changeSign4);
            } else {
                BigDecimalInt result;
                result = changeSign4.operator-(changeSign3);
                result.Sign = true;
                return result;
            }

//            for(int i = anotherDec.size()-1; i >= 0; i--){
//                if(remove){
//                    anotherDec.num[i]--;
//                }
//                digit1 = anotherDec.num[i] - 48;    // -100
//                digit2 = this->num[i] - 48;         // -999
//                if (digit1 < digit2){
//                    remove = true;
//                    digit1 += 10;
//                    subtraction = digit1 - digit2;
//                    to_char = subtraction + 48;
//                    result.num = to_char + result.num;
//                } else {
//                    remove = false;
//                    subtraction = digit1 - digit2;
//                    to_char = subtraction + 48;
//                    result.num = to_char + result.num;
//                }
//            }
//            *this = temp;
//            return result;
        }
    } else if(this->operator>(anotherDec)){
        return this->summation(anotherDec);
    } else {
        BigDecimalInt changeSign = *this;
        changeSign.Sign = true;
        return changeSign.summation(anotherDec);
    }
}


bool BigDecimalInt::operator< (BigDecimalInt anotherDec){
    if (this->sign() == 0 && anotherDec.sign() == 1) {
        return false;
    } else if (this->sign() == 1 && anotherDec.sign() == 0) {
        return true;
    } else if (this->sign() == 0 && anotherDec.sign() == 0 && this->size() < anotherDec.size()) {
        return true;
    } else if (this->sign() == 0 && anotherDec.sign() == 0 && this->size() > anotherDec.size()) {
        return false;
    } else if (this->sign() == 0 && anotherDec.sign() == 0 && this->size() == anotherDec.size()) {
        for (int i = 0; i < anotherDec.size(); ++i) {
            if (this->num[i] < anotherDec.num[i]) {
                return true;
            } else if (this->num[i] > anotherDec.num[i]) {
                return false;
            }
        }
        return false;
    } else if (this->sign() == 1 && anotherDec.sign() == 1 && this->size() < anotherDec.size()) {
        return false;
    } else if (this->sign() == 1 && anotherDec.sign() == 1 && this->size() > anotherDec.size()) {
        return true;
    } else if (this->sign() == 1 && anotherDec.sign() == 1 && this->size() == anotherDec.size()) {
        for (int i = 0; i < anotherDec.size(); ++i) {
            if (this->num[i] < anotherDec.num[i]) {
                return false;
            } else if (this->num[i] > anotherDec.num[i]) {
                return true;
            }
        }
        return false;
    }
    return false;
}

BigDecimalInt& BigDecimalInt::operator= (const BigDecimalInt& anotherDec){
    if(this == &anotherDec){
        return *this;
    }
    this->num = anotherDec.num;
    this->Sign = anotherDec.Sign;
    return *this;
}

bool BigDecimalInt::operator==(BigDecimalInt &anotherDec){
    if(this->sign() != anotherDec.sign() || this->size() != anotherDec.size()){
        return false;
    } else{
        for (int i = 0; i < anotherDec.size(); ++i) {
            if(anotherDec.num[i] != this->num[i]){
                return false;
            }
        }
        return true;
    }
}

bool BigDecimalInt::operator> (BigDecimalInt anotherDec) {
    if (this->sign() == 0 && anotherDec.sign() == 1) {
        return true;
    } else if (this->sign() == 1 && anotherDec.sign() == 0) {
        return false;
    } else if (this->sign() == 0 && anotherDec.sign() == 0 && this->size() > anotherDec.size()) {
        return true;
    } else if (this->sign() == 0 && anotherDec.sign() == 0 && this->size() < anotherDec.size()) {
        return false;
    } else if (this->sign() == 0 && anotherDec.sign() == 0 && this->size() == anotherDec.size()) {
        for (int i = 0; i < anotherDec.size(); ++i) {
            if (this->num[i] > anotherDec.num[i]) {
                return true;
            } else if (this->num[i] < anotherDec.num[i]) {
                return false;
            }
        }
        return false;
    } else if (this->sign() == 1 && anotherDec.sign() == 1 && this->size() > anotherDec.size()) {
        return false;
    } else if (this->sign() == 1 && anotherDec.sign() == 1 && this->size() < anotherDec.size()) {
        return true;
    } else if (this->sign() == 1 && anotherDec.sign() == 1 && this->size() == anotherDec.size()) {
        for (int i = 0; i < anotherDec.size(); ++i) {
            if (this->num[i] > anotherDec.num[i]) {
                return false;
            } else if (this->num[i] < anotherDec.num[i]) {
                return true;
            }
        }
        return false;
    }
    return false;
}


int BigDecimalInt::size() {
    int count = 0;
    for (auto item: num) {
        count++;
    }
    return count;
}

int BigDecimalInt::sign() {
    if(Sign){
        return 1;
    }else {
        return 0;
    }
}

ostream& operator << (ostream& out, BigDecimalInt& b){
    if(b.sign()){
        out << "-";
        for (char item: b.num) {
            out << item;
        }
    }else {
        for (char item: b.num) {
            out << item;
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
        cout << "Please enter the number with only one decimal point" << endl;
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
    (*real) = bigInteger.num;
    for (int i = 0; i <5 ; ++i) {
        (*real).push_back('0');
    }
    realSign = bigInteger.Sign;
    point = bigInteger.num.size();
}

BigReal::BigReal(const BigReal &other) : BigReal(*other.real){
    cout<<"Copy constructor is called"<<endl;
}

BigReal::BigReal(BigReal &&other) {
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

BigReal& BigReal:: operator=(BigReal &other) {
    *(this->real) = *other.real;
    point = other.point;
    realSign = other.realSign;
}
BigReal& BigReal::operator=(BigReal &&other) {
    *(this->real) = *other.real;
    point = other.point;
    realSign = other.realSign;
    other.real= nullptr;
    other.point = 0;
    realSign = false;
}

// ---------------------------------------- Noor Eyad - 20210499 -----------------------------------------------

BigReal BigReal::operator+(BigReal &other) {

}

BigReal BigReal::operator-(BigReal &other) {

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
    }else if(this->point > anotherReal.point && !this->realSign){             // 10.1       1.1
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
    if(this->point != anotherReal.point){
        return false;
    } else if(this->realSign != anotherReal.realSign){
        return false;
    } else if(this->size() != anotherReal.size()){
        return false;
    } else {
        for (int i = 0; i < this->size(); ++i) {
            if (this->real[i] != anotherReal.real[i]) {
                return false;
            }
        }
        return true;
    }
}

int BigReal::size() {
    int count = 0;
    for (auto item: *real) {
        count++;
    }
    for (int i = count-1; i >= point; --i) {
        if((*real)[i] == '0'){
            (*real).erase(i,1);
            count--;
        } else {
            break;
        }
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
