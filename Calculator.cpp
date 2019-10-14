//
// Created by 汪晓成 on 2019/9/28.
//

#include "Calculator.h"

char * Calculator::infix_to_suffix(char * exp) {
    ArrayStack<char> stack(strlen(exp));//栈中只放运算符
    char * Pexp = new char[2*strlen(exp)+1];//存取后缀表达式
    exp = turnfushu(exp);
    int j = 0;
    for (int i = 0; i < strlen(exp)+1; ++i) {
        if(exp[i]=='\0'){//清栈，把栈中的元素全部输出
            char temp;
            while (!stack.IsEmpty()) {
                stack.Pop(temp);
                if(temp == '('){
                    cout<<"错误"<<endl;
                    return 0;
                }
                Pexp[j++] = temp;
            }
            Pexp[j++] = '\0';
            return Pexp;
        }
        if((exp[i]<='9'&&exp[i]>='0')||exp[i]=='!'||exp[i]=='.')
            Pexp[j++] = exp[i];
        else {
            if(exp[i] == '(' ||exp[i] == ')') {
                if (exp[i] == '(')
                    stack.Push(exp[i]);
                else {
                    if(stack.IsEmpty()){
                        cout<<"错误"<<endl;
                        return 0;
                    }
                    char temp;
                    stack.Pop(temp);
                    while (temp != '(') {
                        Pexp[j++] = temp;
                        stack.Pop(temp);
                    }
                }
            }
            else{
                Pexp[j++] = ' ';//可以实现多位数
                char temp;
                while (!stack.IsEmpty()) {//判断优先级，优先级低则一直出栈加到字符串后面
                    stack.Pop(temp);
                    if(cmpop(exp[i],temp)>=0||temp=='(') {//相等要倒续放置,开括号即直接压,优先级高则压入
                        stack.Push(temp);
                        break;
                    }
                    Pexp[j++] = temp;
                }
                stack.Push(exp[i]);
            }
        }
    }
    return Pexp;
}

int Calculator::turnop(char op1) {
    switch (op1){
        case '+':
        case '-':
            return 1;
        case '/':
        case '*':
            return 2;
            //其他运算可以拓展
        default:
            return 0;
    }
}

int Calculator::cmpop(char op1, char op2) {
    return turnop(op1)-turnop(op2);
}

double Calculator::calculator(char *exp) {
    return cal_suffix(infix_to_suffix(exp));
}

double Calculator::cal(double num1, double num2, char op) {
    double res;
    switch (op){//  可用工厂模式
        case '+':
            res = num1 + num2;
            break;
        case '-':
            res = num1 - num2;
            break;
        case '*':
            res = num1 * num2;
            break;
        case '/':
            if(num2==0) {
                cout << "错误";
                exit(1);
            }
            res = num1 / num2;
            break;
        default:
            return 1;
    }
    return res;
}

double Calculator::cal_suffix(char *exp) {
    int i = 0;
    double res = 0;
    ArrayStack<double> stack(strlen(exp));//栈中只放数据，碰见一个运算符即将两个栈顶元素计算后继续压入
    while (exp[i] != '\0') {
        if ((exp[i] <= '9' && exp[i] >= '0')||exp[i]=='!') {
            char * temp1= &exp[i],*temp2 = &exp[i];
            int count = 0;
            while((*temp1 <= '9' && *temp1 >= '0')||*temp1=='!'||*temp1=='.'){
                temp1++;
                if(*temp1 == '.'||count!=0)
                    count++;
            }
            double temp = 0;
            for (int j = 0; temp1 != temp2; ++j) {
                temp1--;
                if(*temp1 == '!') {
                    temp = -temp;
                    i++;
                    break;
                }
                if(*temp1 == '.'){
                    i++;
                    j--;
                    continue;
                }
                temp += (*temp1-'0') * pow(10,j);
                i++;
            }
            if(count!=0)
                temp *= pow(10,-count+2);
            stack.Push(temp);
            i--;
        }
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
            double temp[2];
            if(stack.IsEmpty()) {
                cout << "错误";
                exit(1);
            }
            stack.Pop(temp[0]);
            if(stack.IsEmpty()) {
                cout << "错误";
                exit(1);
            }
            stack.Pop(temp[1]);
            stack.Push(cal(temp[1],temp[0],exp[i]));
        }
        i++;
    }
    stack.Pop(res);
    //stack.Pop(res);
    return res;
}

char * Calculator::turnfushu(char *exp) {
    char * exp1 = new char[strlen(exp)];
    if(exp[0]=='-')
        exp1[0]='!';
    else
        exp1[0] = exp[0];
    int i = 1;
    while(exp[i]!='\0'){
        if(exp[i] == '-'&&!isnumber(exp[i-1])) {
            exp1[i] = '!';
            continue;
        }
        exp1[i] = exp[i];
        if(exp[i]=='+'||exp[i]=='*'||exp1[i]=='-'||exp[i]=='/') {
            if(!isnumber(exp[i-1])||!isnumber(exp[i+1])) {
                cout << "错误";
                exit(1);
            }
        }
        i++;
    }
    return exp1;
}

bool Calculator::isnumber(char a) {
    return a <= '9' && a >= '0';
}
