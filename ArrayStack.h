//
// Created by 汪晓成 on 2019/9/28.
//

#ifndef HW3_ARRAYSTACK_H
#define HW3_ARRAYSTACK_H


#include <iostream>
using namespace std;

template <class T>
class Stack {
public:
void Clear();
bool Push(const T item);
bool Pop(T& item);
bool Top(T& item);
bool IsEmpty();
bool IsFull;
};

template <class T>
class ArrayStack : public Stack<T> {
public:
    ArrayStack(int size)
    {
        maxSize = size;
        top = -1;
        st = new T[maxSize];
    }
    ArrayStack()
    {
        top = -1;
    }
    ~ArrayStack()
    {
        delete[] st;
    }
    void Clear()
    {
        top = -1;
    }
    /*
	TODO:1.3-a. 入栈操作，并判断栈是否为满,若栈已满，则打印cout << "栈满溢出" << endl;返回false。否则将item入栈，返回true
	返回值说明：成功入栈，返回true，否则返回false。
	 */
    bool Push(const T item)
    {
        if(top==maxSize-1)
        {
            cout << "栈满溢出" << endl;
            return false;
        }
        else
        {
            top++;
            st[top]=item;
            return true;
        }
    }
    /*
	TODO:1.3-b 出栈操作，并判断栈是否为空，若为空，则打印cout << "栈为空，不能进行删除操作" << endl;返回false。
	否则，将栈顶元素的值取出来赋值给item，进行出栈操作，返回true
	返回值说明：如果出栈成功，返回true，否则返回false。
	 */
    bool Pop(T& item)
    {
        if(top==-1)
        {
            cout << "栈为空，不能进行删除操作" << endl;
            return false;
        }
        else
        {
            item=st[top];
            top--;
            return true;
        }
    }
    /*
	TODO:1.3-c 读取栈顶元素，但不删除，判断栈是否为空,若为空，则打印cout << "栈为空，不能读取栈顶元素" << endl;返回false
	否则，将栈顶元素取出，并赋值给item，返回true。
	返回值说明：成功读取栈顶元素，返回true，否则返回false。
	 */
    bool Top(T& item)
    {
        if(top==-1)
        {
            cout << "栈为空，不能读取栈顶元素" << endl;
            return false;
        }
        else
        {
            item=st[top];
            return true;
        }
    }
    bool IsEmpty(){
        return top == -1;
    };

private:
    int maxSize; //栈中最多保存的元素个数
    int top; //指向栈顶，初始化为-1，入栈时top+1，出栈时top-1
    T* st; //栈
};


#endif //HW3_ARRAYSTACK_H
