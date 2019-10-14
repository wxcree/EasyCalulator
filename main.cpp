#include <iostream>
#include "Calculator.h"
using namespace std;
int main(){
    Calculator calculator;//不支持10以上 不支持负数 不支持小数 运算符只支持加减乘除
    //cout<<calculator.infix_to_suffix("1.1+1")<<endl;
    cout<<calculator.calculator("-2.1+3.2/0.2");
}