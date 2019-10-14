//
// Created by 汪晓成 on 2019/9/28.
//

#ifndef HW3_LINKSTACK_H
#define HW3_LINKSTACK_H


#include <iostream>
using namespace std;

template <class T>
class LinkNode {
public:
    T data; //数据域
    LinkNode<T>* link; //指向后继指针的结点
    LinkNode(const T& el, LinkNode<T>* ptr = 0)
    {
        data = el;
        link = ptr;
    }
};
template <class T>
class LinkStack {
public:
    LinkStack()
    {
        top = NULL;
        size = 0;
    }
    ~LinkStack()
    {
        Clear();
    }
    void Clear()
    {
        while (top != NULL) {
            LinkNode<T>* tmp = top;
            top = top->link;
            delete tmp;
        }
        size = 0;
    }

    /*
	TODO:1.4-a.	入栈操作,将item入栈，并返回true
	 */
    bool Push(const T item)
    {
        LinkNode<T>*tem=new LinkNode<T>(item);
        tem->link=top;
        top=tem;
        size++;
        return true;
    }
    /*
	TODO:1.4-b.	出栈操作，并判断栈是否为空，将栈顶元素赋值给item
	返回值说明：出栈成功，返回true，否则返回false
	注意：如果栈为空，则打印cout << "栈为空，不能执行出栈操作" << endl;并返回false
	 */
    bool Pop(T& item)
    {
        if(top==NULL)
        {
            cout << "栈为空，不能执行出栈操作" << endl;
            return false;
        }
        else
        {
            item=top->data;
            LinkNode<T>*tem=top;
            top=top->link;
            delete tem;
            size--;
            return true;
        }
    }
    /*
	TODO：1.4-c.	读取栈顶元素，但不删除，判断栈是否为空。
	如果栈为空，则输出打印cout << "栈为空，不能读取栈顶元素" << endl;并返回false，
	否则，将栈顶元素获取并赋值给item, 返回true。
	 */
    bool Top(T& item)
    {
        if(top==NULL)
        {
            cout << "栈为空，不能读取栈顶元素" << endl;
            return false;
        }
        else
        {
            item=top->data;
            return true;
        }
    }

private:
    LinkNode<T>* top; //指向链式栈栈顶的指针
    int size; //栈中元素个数
};



#endif //HW3_LINKSTACK_H
