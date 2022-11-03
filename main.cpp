#include <iostream>
#include "BigReal.h"
using namespace std;

int main(){
//    BigDecimalInt str1 = {"-87"};
//    BigDecimalInt str2 = {"-1878764"};
//    BigDecimalInt str3 = {"-871726381"};
//    BigDecimalInt str4 = {"+78162836872387"};
//    BigDecimalInt str5 = {"127836182612387"};
//    BigDecimalInt str6 = {-871726381};
//    BigDecimalInt str7 = {-12387};
//    BigDecimalInt sum = str1 + str2;
//    BigDecimalInt sub = str1 - str2;
//    cout << sum << endl;
//    cout << sub << endl;
//    cout << str1 << endl;
//    cout << str2 << endl;
//    if(str1 > str2){
//        cout << "first is greater" << endl;
//    } else {
//        cout << "first is not greater" << endl;
//    }
//    if(str4 < str7){
//        cout << "first is smaller" << endl;
//    } else {
//        cout << "first is not smaller" << endl;
//    }
//    if(str6 == str3){
//        cout << "both are equal" << endl;
//    } else {
//        cout << "both are different" << endl;
//    }
//    str2 = str3;
//    cout << str2 << "   " << str3;


//BigDecimalInt trial = 3872;
//BigReal num (1.1);
//BigReal num2{num};
//BigReal num3{trial};

BigReal realDouble(1352.889666);
BigReal realString("28248282.622882828");
BigReal realCopy(realString);
BigReal decimalNum (BigDecimalInt("7246822882"));
cout<<realDouble<<endl;
cout<<decimalNum<<endl;
cout<<realString<<endl;
BigReal wrongNumber("1.4.5.673288");
}