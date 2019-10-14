//
// Created by 汪晓成 on 2019/9/28.
//

#ifndef HW3_CALCULATOR_H
#define HW3_CALCULATOR_H

#include <string>
#include <iostream>
#include <math.h>
#include "ArrayStack.h"
using namespace std;

class Calculator {
public:
    double calculator(char * exp);
    char * infix_to_suffix(char * exp);
private:
    int turnop(char op1);//把操作符转换为数字
    int cmpop(char op1,char op2);//负为小于，0为等于，正为大于
    //char * infix_to_suffix(char * exp);
    double cal_suffix(char * exp);
    double cal(double num1,double num2,char op);
    char * turnfushu(char * exp);
    bool isnumber(char a);
};


#endif //HW3_CALCULATOR_H
