//
//  circular_list.hpp
//  data_structure_learning
//
//  Created by 王久亮 on 2018/5/17.
//  Copyright © 2018年 王久亮. All rights reserved.
//

#ifndef CIRCULAR_LIST_H_
#define CIRCULAR_LIST_H_

#include <iostream>

/**
 * 循环链表类
 */
template <class T>
class CircularList {
private:
    class Node {
    public:
        T m_data;
        Node * m_next;
        Node(Node * next = nullptr) : m_next(next) {}
        Node(T data, Node * next = nullptr) : m_data(data), m_next(next) {}
    };
    Node * head;                                                //头指针
    Node * rear;                                                //尾指针
    
    //私有函数
    Node * Locate(int i) const;
    Node * Search(const T & item) const;
public:
    //构造析构
    CircularList();                                              //构造函数
    virtual ~CircularList();                                     //析构函数
    CircularList(const CircularList & list);                     //拷贝构造函数
    CircularList & operator=(const CircularList & list);         //复制赋值操作符
    CircularList(CircularList && list);                          //移动构造函数
    CircularList & operator=(CircularList && list);              //移动赋值操作符
    
    //成员函数
    void MakeEmpty();                                            //清空链表
    int Length() const;                                          //计算表长
    bool IsEmpty() const;                                        //判断表空
    bool getData(int i, T & item) const;                         //获取指定元素
    bool setData(int i, const T & item);                         //设置指定元素
    bool InsertBack(int i, const T & item);                      //在指定位置后面插入元素
    bool Remove(int i, T & item);                                //删除元素
    void Input();                                                //输入
    void Output() const;                                         //输出
    
    //友元
    template <class U>
    friend std::ostream & operator<<(std::ostream & os,          //重载<<操作符
                                     const CircularList<U> & list);
};

/**********************************实现部分************************************/

//构造析构

/**
 * 构造函数
 */
template <class T>
CircularList<T>::CircularList() {
    rear = head = new Node;
    rear -> m_next = head;
}
/**
 * 析构函数
 */
template <class T>
CircularList<T>::~CircularList() {
    MakeEmpty();
}

/**
 * 复制构造函数
 */
template <class T>
CircularList<T>::CircularList(const CircularList & list) {
    rear = head = new Node;
    rear -> m_next = head;
    Node * list_ptr = list.head -> m_next;
    while (list_ptr -> m_next != list.head) {
        Node * new_node = new Node(list_ptr -> m_data);
        new_node -> m_next = rear -> m_next;
        rear -> m_next = new_node;
        rear = new_node;
        list_ptr = list_ptr -> m_next;
    }
}

/**
 * 复制赋值操作符
 */
template <class T>
CircularList<T> & CircularList<T>::operator=(const CircularList<T> & list) {
    MakeEmpty();
    rear = head = new Node;
    rear -> m_next = head;
    Node * list_ptr = list.head -> m_next;
    while (list_ptr -> m_next != list.head) {
        Node * new_node = new Node(list_ptr -> m_data);
        new_node -> m_next = rear -> m_next;
        rear -> m_next = new_node;
        rear = new_node;
        list_ptr = list_ptr -> m_next;
    }
    return *this;
}

/**
 * 移动构造函数
 */
template <class T>
CircularList<T>::CircularList(CircularList && list) {
    head = list.head;
    rear = list.rear;
    list.head = nullptr;
    list.rear = nullptr;
}

/**
 * 移动赋值操作符
 */
template <class T>
CircularList<T> & CircularList<T>::operator=(CircularList<T> && list) {
    MakeEmpty();
    head = list.head;
    rear = list.rear;
    list.head = nullptr;
    list.rear = nullptr;
    return *this;
}

//私有函数

/**
 * 定位第i个元素
 */
template <class T>
typename CircularList<T>::Node * CircularList<T>::Locate(int i) const {
    int index = 0;
    Node * curr_ptr = head -> m_next;
    while (curr_ptr != head) {
        ++ index;
        if (index >= i) {
            break;
        }
        curr_ptr = curr_ptr -> m_next;
    }
    return curr_ptr == head ? nullptr:curr_ptr;
}

/**
 * 查找指定元素，找不到返回空指针
 */
template <class T>
typename CircularList<T>::Node * CircularList<T>::Search(const T & item) const {
    Node * curr_ptr = head -> m_next;
    while (curr_ptr != head) {
        if (item == curr_ptr -> m_data) {
            return curr_ptr;
        }
        curr_ptr = curr_ptr -> m_next;
    }
    return nullptr;
}
//成员函数

/**
 * 清空列表
 */
template <class T>
void CircularList<T>::MakeEmpty() {
    if (head == nullptr || rear == nullptr) { //兼容移动构造函数将头节点置为空的情况
        return;
    }
    
    Node * curr_ptr = head -> m_next;
    while (curr_ptr != head) {
        head -> m_next = curr_ptr -> m_next;
        delete curr_ptr;
        curr_ptr = head -> m_next;
    }
    delete head;
    rear = head = nullptr;
}

/**
 * 计算链表长度
 */
template <class T>
int CircularList<T>::Length() const {
    int count = 0;
    Node * curr_ptr = head -> m_next;
    while (curr_ptr != head) {
        ++ count;
        curr_ptr = curr_ptr -> m_next;
    }
    return count;
}

/**
 * 判断表空
 */
template <class T>
bool CircularList<T>::IsEmpty() const {
    return head == rear -> next;
}

/**
 * 获取第i个元素
 */
template <class T>
bool CircularList<T>::getData(int i, T & item) const {
    int fact_i = i % Length();
    if (fact_i == 0) {
        fact_i = Length();
    }
    
    Node * curr_ptr = Locate(fact_i);
    if (curr_ptr != nullptr) {
        item = curr_ptr -> m_data;
        return true;
    }
    return false;
}

/**
 * 设置第i个元素
 */
template <class T>
bool CircularList<T>::setData(int i, const T & item) {
    int fact_i = i % Length();
    if (fact_i == 0) {
        fact_i = Length();
    }
    
    Node * curr_ptr = Locate(fact_i);
    if (curr_ptr != nullptr) {
        curr_ptr -> m_data = item;
        return true;
    }
    return false;
}

/**
 * 在第i个元素后插入元素
 */
template <class T>
bool CircularList<T>::InsertBack(int i, const T & item) {
    int fact_i = i % Length();
    if (fact_i == 0) {
        fact_i = Length();
    }
    
    Node * curr_ptr = Locate(fact_i);
    if (curr_ptr != nullptr) {
        Node * new_node = new Node(item);
        new_node -> m_next = curr_ptr -> m_next;
        curr_ptr -> m_next = new_node;
        if (new_node -> m_next == head) {
            rear = new_node;
        }
        return true;
    }
    return false;
}

/**
 * 删除第i个元素
 */
template <class T>
bool CircularList<T>::Remove(int i, T & item) {
    int fact_i = i % Length();
    if (fact_i == 0) {
        fact_i = Length();
    }
    
    Node * curr_ptr = Locate(fact_i - 1);
    if (curr_ptr != nullptr) {
        if (curr_ptr -> m_next == rear) {
            rear = curr_ptr;
        }
        Node * del_ptr = curr_ptr -> m_next;
        curr_ptr -> m_next = del_ptr -> m_next;
        delete del_ptr;
        return true;
    }
    return false;
}

/**
 * 尾插法建立链表
 */
template <class T>
void CircularList<T>::Input() {
    std::cout << "使用尾插法建立链表：\n";
    MakeEmpty();
    rear = head = new Node;
    rear -> m_next = head;
    
    std::cout << "请输入结束的tag：\n";
    T end_tag;
    std::cin >> end_tag;
    
    std::cout << "开始输出元素(" << "输入" << end_tag << "结束): \n";
    T item;
    std::cin >> item;
    while (item != end_tag) {
        Node * new_node = new Node(item);
        new_node -> m_next = rear -> m_next;
        rear -> m_next = new_node;
        rear = new_node;
        std::cin >> item;
    }
}

/**
 * 输出
 */
template <class T>
void CircularList<T>::Output() const {
    std::cout << "链表中元素为：\n";
    Node * curr_ptr = head -> m_next;
    std::cout << "head-";
    while (curr_ptr != head) {
        std::cout << curr_ptr -> m_data << "-";
        curr_ptr = curr_ptr -> m_next;
    }
    std::cout << "head";
}

//友元
template <class T>
std::ostream & operator<<(std::ostream & os, const CircularList<T> & list) {
    os << "链表中元素为：\n";
    typename CircularList<T>::Node * curr_ptr = list.head -> m_next;
    os << "head-";
    while (curr_ptr != list.rear) {
        os << curr_ptr -> m_data << "-";
        curr_ptr = curr_ptr -> m_next;
    }
    os << "head";
    return os;
}
#endif /* CIRCULAR_LIST_H_ */
