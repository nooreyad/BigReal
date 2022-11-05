#include <iostream>
#include<vector>
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
//BigReal num4(111.812348);
//BigReal num5(111.812349);
//
//if(num4 < num5){
//    cout << "yes" << endl;
//} else {
//    cout << "no";
//}//cout << num4.size() << endl << num5.size();
//
//BigReal num;
//cin >> num;
//cout << num << endl;
////cout << num5;


BigReal numdecimal(BigDecimalInt("3789320280208803802"));
cout<<numdecimal<<endl;


////TESTING COPY AND MOVE
//BigReal num1("236186818.9404"), num2("3747474748.77");
//BigReal num3(num1); // calls copy constructor
//BigReal num4 = num2; //calls copy constructor // same as num4(num2)
//cout<<num4<<endl;
//BigReal num5("637377383.88"), num6(8389384894.88);
//num5 = num6; //calls assignment operator  //same as num5.operator=(num6)
//cout<<num5<<endl;
//vector<BigReal>vec;
//vec.push_back(BigReal("12792079.88")); //inserting rvalue of type BigReal in vec
//cout<<vec[0]<<endl;
//vec[1]=BigReal("945303030.55"); //Calls the move assignment
//cout<<vec[1]<<endl; //It doesn't print
}