//
//  linked_list.hpp
//  data_structure_learning
//
//  Created by 王久亮 on 2018/5/16.
//  Copyright © 2018年 王久亮. All rights reserved.
//

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>

/**
 * 单链表类
 */
template <class T>
class LinkedList {
private:
    // 节点类
    class Node {
    public:
        T m_data;
        Node * m_next;
        Node(T data, Node * next = nullptr) {m_data = data;m_next = next;}
        explicit Node(Node * next = nullptr) {m_next = next;}
    };
    Node * head;
    
    //私有函数
    Node * Search(T & item) const;
    Node * Locate(int i);
public:
    //构造析构
    LinkedList() {head = new Node;}                                      //构造函数
    virtual ~LinkedList();                                               //析构函数
    LinkedList(const LinkedList & list);                                 //复制构造函数
    LinkedList & operator=(const LinkedList & list);                     //复制赋值操作符
    LinkedList(LinkedList && list);                                      //移动构造函数
    LinkedList & operator=(LinkedList && list);                          //移动赋值操作符
    
    //成员函数
    void MakeEmpty();                                                    //清空链表
    int Length() const;                                                  //计算链表长度
    bool getData(int i, T & item) const;                                 //获取链表元素
    bool setData(int i, const T & item);                                 //设置链表元素
    bool InsertBack(int i, const T & item);                              //插入元素
    bool Remove(int i);                                                  //删除元素
    bool IsEmpty() const {return head -> m_next == nullptr;}             //判断表空
    bool IsFull() const {return false;}                                  //判断表满
    void Sort();                                                         //排序
    void InputFront();                                                   //前插法建立链表
    void InputRear();                                                    //尾插法建立链表
    void Output() const;                                                 //输出
    
    //友元
    template <class U>
    friend std::ostream & operator<<(std::ostream os,                    //重载<<操作符
                                     const LinkedList<U> & list);
};

/*********************************实现部分*************************************/

//构造析构

/**
 * 构造函数
 */
template <class T>
LinkedList<T>::~LinkedList() {
    MakeEmpty();
}

/**
 * 复制构造函数
 */
template <class T>
LinkedList<T>::LinkedList(const LinkedList & list) {
    head = new Node;
    
    Node * curr_ptr = head;
    Node * list_ptr = list.head;
    list_ptr = list_ptr -> m_next;
    while (list_ptr != nullptr) {
        Node * new_node = new Node(list_ptr -> m_data);
        new_node -> m_next = curr_ptr -> m_next;
        curr_ptr -> next = new_node;
        curr_ptr = curr_ptr -> m_next;
        list_ptr = list_ptr -> m_next;
    }
}

/**
 * 复制赋值操作符
 */
template <class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> & list) {
    MakeEmpty();
    head = new Node;
    
    Node * curr_ptr = head;
    Node * list_ptr = list.head;
    list_ptr = list_ptr -> m_next;
    while (list_ptr != nullptr) {
        Node * new_node = new Node(list_ptr -> m_data);
        new_node -> m_next = curr_ptr -> m_next;
        curr_ptr -> next = new_node;
        curr_ptr = curr_ptr -> m_next;
        list_ptr = list_ptr -> m_next;
    }
    return *this;
}

/**
 * 移动构造函数
 */
template <class T>
LinkedList<T>::LinkedList(LinkedList && list) {
    head = list.head;
    list.head = nullptr;
}

/**
 * 移动赋值操作符
 */
template <class T>
LinkedList<T> & LinkedList<T>::operator=(LinkedList<T> && list) {
    MakeEmpty();
    head = list.head;
    list.head = nullptr;
}

//私有函数

/**
 * 定位第i个节点的地址
 */
template <class T>
typename LinkedList<T>::Node * LinkedList<T>::Locate(int i) {
    int index = 0;
    Node * curr_ptr = head -> m_next;
    while (curr_ptr != nullptr) {
        index ++;
        if (index >= i) {
            break;
        }
        curr_ptr = curr_ptr -> m_next;
    }
    return curr_ptr;
    
}

/**
 * 查找元素位置
 */
template <class T>
typename LinkedList<T>::Node * LinkedList<T>::Search(T & item) const {
    Node * curr_ptr = head -> m_next;
    while (curr_ptr != nullptr) {
        if (curr_ptr -> m_data == item) {
            return curr_ptr;
        }
        curr_ptr = curr_ptr -> m_next;
    }
    return nullptr;
}

//成员函数

/**
 * 将表置为空
 */
template <class T>
void LinkedList<T>::MakeEmpty() {
    Node * curr_ptr = head -> m_next;
    while (curr_ptr != nullptr) {
        head -> m_next = curr_ptr -> m_next;
        delete curr_ptr;
        curr_ptr = head -> m_next;
    }
    delete head;
}

/**
 * 计算链表长度
 */
template <class T>
int LinkedList<T>::Length() const {
    int count = 0;
    Node * curr_ptr = head -> m_next;
    while (curr_ptr != nullptr) {
        ++ count;
        curr_ptr = curr_ptr -> m_next;
    }
    return count;
}

/**
 * 获取指定位置的元素
 */
template <class T>
bool LinkedList<T>::getData(int i, T & item) const {
    Node * curr_ptr = Locate(i);
    if (curr_ptr != nullptr) {
        item = curr_ptr -> m_data;
        return true;
    }
    return false;
}

/**
 * 设置指定位置的元素
 */
template <class T>
bool LinkedList<T>::setData(int i, const T & item) {
    Node * curr_ptr = Locate(i);
    if (curr_ptr != nullptr) {
        curr_ptr -> m_data = item;
        return true;
    }
    return false;
}

/**
 * 在第i个元素后面插入节点
 */
template <class T>
bool LinkedList<T>::InsertBack(int i, const T & item) {
    Node * curr_ptr = Locate(i);
    if (curr_ptr != nullptr) {
        Node * new_node = new Node(item);
        new_node -> m_next = curr_ptr -> m_next;
        curr_ptr -> m_next = new_node;
        return true;
    }
    return false;
}

/**
 * 删除第i个元素
 */
template <class T>
bool LinkedList<T>::Remove(int i) {
    Node * curr_ptr = Locate(i - 1);
    if (curr_ptr != nullptr && curr_ptr -> m_next != nullptr) {
        Node * del_ptr = curr_ptr -> m_next;
        curr_ptr -> m_next = del_ptr -> m_next;
        delete del_ptr;
        return true;
    }
    return false;
}

/**
 * 排序(暂不实现)
 */
template <class T>
void LinkedList<T>::Sort() {
    
}

/**
 * 头插法建立链表
 */
template <class T>
void LinkedList<T>::InputFront() {
    std::cout << "使用前插法建立链表：\n";
    MakeEmpty();
    head = new Node;
    
    std::cout << "请输入结束的tag：\n";
    T end_tag;
    std::cin >> end_tag;
    
    std::cout << "开始输出元素(" << "输入" << end_tag << "结束): \n";
    T item;
    std::cin >> item;
    while (item != end_tag) {
        Node * new_node = new Node(item);
        new_node -> m_next = head -> m_next;
        head -> m_next = new_node;
        std::cin >> item;
    }
}

/**
 * 尾插法建立链表
 */
template <class T>
void LinkedList<T>::InputRear() {
    std::cout << "使用尾插法建立链表：\n";
    MakeEmpty();
    head = new Node;
    
    std::cout << "请输入结束的tag：\n";
    T end_tag;
    std::cin >> end_tag;
    
    std::cout << "开始输出元素(" << "输入" << end_tag << "结束): \n";
    Node * last = head;
    T item;
    std::cin >> item;
    while (item != end_tag) {
        Node * new_node = new Node(item);
        last -> m_next = new_node;
        last = new_node;
        std::cin >> item;
    }
}

/**
 * 输出
 */
template <class T>
void LinkedList<T>::Output() const {
    std::cout << "链表中元素为：\n";
    Node * curr_ptr = head -> m_next;
    while (curr_ptr != nullptr) {
        std::cout << curr_ptr -> m_data << "-";
        curr_ptr = curr_ptr -> m_next;
    }
    std::cout << "^";
}

/**
 * 重载<<操作符
 */
template <class T>
std::ostream & operator<<(std::ostream & os, const LinkedList<T> & list) {
    os << "链表中元素为；\n";
    typename LinkedList<T>::Node * curr_ptr = list.head -> m_next;
    while (curr_ptr != nullptr) {
        os << curr_ptr -> m_data << "-";
    }
    os << "^";
    return os;
}

#endif /* LINKED_LIST_H_ */

