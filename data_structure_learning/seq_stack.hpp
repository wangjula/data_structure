//
//  seq_stack.hpp
//  data_structure_learning
//
//  Created by 王久亮 on 2018/6/29.
//  Copyright © 2018年 王久亮. All rights reserved.
//

#ifndef STATCK_H_
#define STATCK_H_

#include <iostream>

const int kIncrementSize = 20;                                 //栈每次扩容大小

/**
 * 顺序栈类
 */
template <class T>
class Stack {
public:
    //构造析构
    explicit Stack(int sz = 50);                              //构造函数
    virtual ~Stack();                                         //析构函数
    Stack(const Stack & s);                                   //复制构造函数
    Stack & operator=(const Stack & s);                       //复制赋值操作符
    Stack(Stack && s);                                        //移动构造函数
    Stack & operator=(Stack && s);                            //移动赋值操作符
    
    //成员函数
    void Push(const T & item);                                //入栈
    void MakeEmpty();                                         //栈置空
    bool Pop(T & item);                                       //出栈
    bool getTop(T & item) const;                              //获取栈顶元素
    bool IsEmpty() const;                                     //判空
    bool IsFull() const;                                      //判满
    int Size() const;                                         //计算栈元素数
    
    //友元
    template <class U>
    friend std::ostream & operator<<(std::ostream & os,       //格式化输出
                                     const Stack<U> & s);
private:
    T * elems;
    int top;
    int max_size;
    void overflowProcess();
};


//============================实现部分===============================

//构造析构
/**
 * 构造函数
 */
template <class T>
Stack<T>::Stack(int sz) : max_size(sz), top(-1) {
    elems = new (std::nothrow) T[max_size];
    assert(elems != nullptr);
};

/**
 * 析构函数
 */
template <class T>
Stack<T>::~Stack() {
    delete [] elems;
};

/**
 * 复制构造函数
 */
template <class T>
Stack<T>::Stack(const Stack<T> & s) {
    max_size = s.max_size;
    top = s.top;
    elems = new (std::nothrow) T[max_size];
    assert(elems != nullptr);
    for (int i = 0; i <= top; ++ i) {
        elems[i] = s.elems[i];
    }
};

/**
 * 复制赋值操作符
 */
template <class T>
Stack<T> & Stack<T>::operator=(const Stack<T> & s) {
    delete [] elems;
    max_size = s.max_size;
    top = s.top;
    elems = new (std::nothrow) T[max_size];
    assert(elems != nullptr);
    for (int i = 0; i <= top; ++ i) {
        elems[i] = s.elems[i];
    }
};

/**
 * 移动构造函数
 */
template <class T>
Stack<T>::Stack(Stack<T> && s) {
    max_size = s.max_size;
    top = s.top;
    elems = s.elems;
    s.elems = nullptr;
};

/**
 * 移动赋值操作符
 */
template <class T>
Stack<T> & Stack<T>::operator=(Stack<T> && s) {
    delete [] elems;
    max_size = s.max_size;
    top = s.top;
    elems = s.elems;
    s.elems = nullptr;
};

//私有函数
/**
 * 溢出扩容处理
 */
template <class T>
void Stack<T>::overflowProcess() {
    max_size = max_size + kIncrementSize;
    T * new_elems = new (std::nothrow) T[max_size];
    assert(new_elems != nullptr);
    for (int i = 0; i <= top; ++ i) {
        new_elems[i] = elems[i];
    }
    delete [] elems;
    elems = new_elems;
    new_elems = nullptr;
};

//成员函数
/**
 * 入栈
 */
template <class T>
void Stack<T>::Push(const T & item) {
    if (IsFull()) {
        overflowProcess();
    }
    elems[++ top] = item;
};

/**
 * 置空
 */
template <class T>
void Stack<T>::MakeEmpty() {
    top = -1;
};

/**
 * 出栈
 */
template <class T>
bool Stack<T>::Pop(T & item) {
    if (top != -1) {
        item = elems[top --];
        return true;
    }
    return false;
};

/**
 * 获取栈顶元素
 */
template <class T>
bool Stack<T>::getTop(T & item) const {
    if (top != -1) {
        item = elems[top];
        return true;
    }
    return false;
};

/**
 * 判空
 */
template <class T>
bool Stack<T>::IsEmpty() const {
    return top == -1;
}

/**
 * 判满
 */
template <class T>
bool Stack<T>::IsFull() const {
    return top == max_size - 1;
}

/**
 * 计算大小
 */
template <class T>
int Stack<T>::Size() const {
    return top + 1;
}

//友元函数
/**
 * 格式化输出
 */
template <class T>
std::ostream & operator<<(std::ostream & os, const Stack<T> & s) {
    os << "栈顶top为：" << s.top << std::endl;
    os << "栈中元素为：\n[";
    for (int i = 0; i <= s.top - 1; ++ i) {
        os << "<" << i << ">:" << s.elems[i] << " ";
    }
    os << "<" << s.top << ">:" << s.elems[s.top] << "]" << std::endl;
    return os;
}
#endif /* STATCK_H_ */
