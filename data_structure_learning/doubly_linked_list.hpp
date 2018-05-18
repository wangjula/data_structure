//
//  doubly_linked_list.hpp
//  data_structure_learning
//
//  Created by 王久亮 on 2018/5/18.
//  Copyright © 2018年 王久亮. All rights reserved.
//

#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

#include <iostream>

template <class T>
class DoublyLinkedList {
public:
    //构造析构
    DoublyLinkedList();
    virtual ~DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList & list);
    DoublyLinkedList & operator=(const DoublyLinkedList & list);
    DoublyLinkedList(DoublyLinkedList && list);
    DoublyLinkedList & operator=(DoublyLinkedList && list);
    
    //成员函数
    int Length() const;
    bool getData(int i, T & item) const;
    bool setData(int i, const T & item);
    bool IsEmpty() const;
    bool Insert(const T & item);
    bool Remove(int i, T & item);
    void MakeEmpty();
    void Input();
    void Output() const;
    
    //友元
    template <class U>
    friend std::ostream & operator<<(std::ostream & os,
                                     const DoublyLinkedList<U> & list);
private:
    class Node {
    public:
        T m_data;
        Node * m_pre;
        Node * m_next;
        Node(T data, Node * pre = nullptr,
             Node * next = nullptr) : m_data(data), m_pre(pre), m_next(next) {}
    };
    Node * head;
    Node * rear;
    
    //私有成员函数
    Node * Locate(int i) const;
    Node * Search(const T & item) const;
};

//构造析构

/**
 * 构造函数
 */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    rear = head = nullptr;
}

/**
 * 析构函数
 */
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    MakeEmpty();
}

/**
 * 复制构造函数
 */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList & list) {
    int length = list.Length();
    Node * list_ptr = list.head;
    for (int i = 0; i < length; ++ i) {
        Node * new_node = new Node(list_ptr -> m_data);
        if (head == nullptr) {
            rear = head = new_node;
            new_node -> m_pre = new_node;
            new_node -> m_next = new_node;
        } else {
            new_node -> m_pre = rear;
            new_node -> m_next = rear -> m_next;
            rear = new_node;
        }
        list_ptr = list_ptr -> m_next;
    }
}

/**
 * 复制赋值操作符
 */
template <class T>
DoublyLinkedList<T> &
DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> & list) {
    MakeEmpty();
    int length = list.Length();
    Node * list_ptr = list.head;
    for (int i = 0; i < length; ++ i) {
        Node * new_node = new Node(list_ptr -> m_data);
        if (head == nullptr) {
            rear = head = new_node;
            new_node -> m_pre = new_node;
            new_node -> m_next = new_node;
        } else {
            new_node -> m_pre = rear;
            new_node -> m_next = rear -> m_next;
            rear = new_node;
        }
        list_ptr = list_ptr -> m_next;
    }
}

/**
 * 移动构造函数
 */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList && list) {
    head = list.head;
    rear = list.rear;
    list.head = nullptr;
    list.rear = nullptr;
}

/**
 * 移动赋值操作符
 */
template <class T>
DoublyLinkedList<T> &
DoublyLinkedList<T>::operator=(DoublyLinkedList<T> && list) {
    MakeEmpty();
    head = list.head;
    rear = list.rear;
    list.head = nullptr;
    list.rear = nullptr;
}

//私有成员函数

/**
 * 定位第i个元素
 */
template <class T>
typename DoublyLinkedList<T>::Node *
DoublyLinkedList<T>::Locate(int i) const {
    if (head == nullptr || i == 0) {
        return nullptr;
    }
    Node * curr_ptr = head;
    while (i > 1) {
        curr_ptr = curr_ptr -> m_next;
        -- i;
    }
    while (i < 0) {
        curr_ptr = curr_ptr -> m_pre;
        ++ i;
    }
    return curr_ptr;
}

/**
 * 查找指定元素
 */
template <class T>
typename DoublyLinkedList<T>::Node *
DoublyLinkedList<T>::Search(const T & item) const {
    Node * curr_ptr = head;
    while (curr_ptr != nullptr
           && (head == rear || curr_ptr != head)) {
        if (curr_ptr -> m_data == item) {
            return curr_ptr;
        }
        curr_ptr = curr_ptr -> m_next;
    }
    return nullptr;
}

//成员函数

/**
 * 计算表长
 */
template <class T>
int DoublyLinkedList<T>::Length() const {
    int count = 0;
    Node * curr_ptr = head;
    if (curr_ptr != nullptr) {
        while (curr_ptr != rear) {               //先遍历到尾节点之前，循环外再遍历节点
            ++ count;
            curr_ptr = curr_ptr -> m_next;
        }
        ++ count;
    }
    return count;
}

/**
 * 获取第i个元素（负号表示反向计算）
 */
template <class T>
bool DoublyLinkedList<T>::getData(int i, T & item) const {
    Node * curr_ptr = Locate(i);
    if (curr_ptr != nullptr) {
        item = curr_ptr -> m_data;
        return true;
    }
    return false;
}

/**
 * 设置第i个元素（负号表示反向计算）
 */
template <class T>
bool DoublyLinkedList<T>::setData(int i, const T & item) {
    Node * curr_ptr = Locate(i);
    if (curr_ptr != nullptr) {
        curr_ptr -> m_data = item;
        return true;
    }
    return false;
}

/**
 *
 */

/**
 * 判断表空
 */
template <class T>
bool DoublyLinkedList<T>::IsEmpty() const {
    return head == nullptr;
}

/**
 * 在rear后插入数据
 */
template <class T>
bool DoublyLinkedList<T>::Insert(const T & item) {
    Node * new_node = new Node(item);
    if (head == nullptr) {
        rear = head = new_node;
        new_node -> m_pre = new_node;
        new_node -> m_next = new_node;
    } else {
        new_node -> m_pre = rear;
        new_node -> m_next = rear -> m_next;
        head -> m_pre = new_node;
        rear -> m_next = new_node;
        rear = new_node;
    }
    return true;
}

/**
 * 在指定位置删除数据
 */
template <class T>
bool DoublyLinkedList<T>::Remove(int i, T & item) {
    Node * curr_ptr = Locate(i);
    if (curr_ptr != nullptr) {
        if (head == rear) {                               //只有一个节点的情况
            item = head -> m_data;
            delete head;
            rear = head = nullptr;
            return true;
        }
        
        curr_ptr -> m_pre -> m_next = curr_ptr -> m_next; //有多个节点的情况
        curr_ptr -> m_next -> m_pre = curr_ptr -> m_pre;
        item = curr_ptr -> m_data;
        if (curr_ptr == head) {
            head = curr_ptr -> m_next;
        }
        if (curr_ptr == rear) {
            rear = curr_ptr -> m_pre;
        }
        delete curr_ptr;
        return true;
    }
    return false;
}

/**
 * 将表置空
 */
template <class T>
void DoublyLinkedList<T>::MakeEmpty() {
    if (head != nullptr) {
        Node * curr_ptr = head;
        Node * del_ptr = nullptr;
        while (curr_ptr != rear) {
            del_ptr = curr_ptr;
            curr_ptr -> m_pre -> m_next = curr_ptr -> m_next;
            curr_ptr -> m_next -> m_pre = curr_ptr -> m_pre;
            curr_ptr = curr_ptr -> m_next;
            delete del_ptr;
        }
        delete curr_ptr;
        rear = head = nullptr;
    }
}

/**
 * 输入
 */
template <class T>
void DoublyLinkedList<T>::Input() {
    std::cout << "使用尾插法建立链表：\n";
    MakeEmpty();
    
    std::cout << "请输入结束的tag：\n";
    T end_tag;
    std::cin >> end_tag;
    
    std::cout << "开始输出元素(" << "输入" << end_tag << "结束): \n";
    T item;
    std::cin >> item;
    while (item != end_tag) {
        Insert(item);
        std::cin >> item;
    }
}

/**
 * 输出
 */
template <class T>
void DoublyLinkedList<T>::Output() const {
    std::cout << "表长为：" << Length() << std::endl;
    std::cout << "表中元素为：" << std::endl;
    std::cout << "head-";
    Node * curr_ptr = head;
    if (curr_ptr != nullptr) {
        while (curr_ptr != rear) {             //先遍历到尾节点之前，循环外再遍历尾节点
            std::cout << curr_ptr -> m_data << "-";
            curr_ptr = curr_ptr -> m_next;
        }
        std::cout << curr_ptr -> m_data << "-";
    }
    std::cout << "head" << std::endl;
}

//友元函数

/**
 * 重载操作符<<
 */
template <class T>
std::ostream & operator<<(std::ostream & os, const DoublyLinkedList<T> & list) {
    os << "表长为：" << list.Length() << std::endl;
    os << "表中元素为：" << std::endl;
    std::cout << "head-";
    typename DoublyLinkedList<T>::Node * curr_ptr = list.head;
    if (curr_ptr != nullptr) {
        while (curr_ptr != list.rear) {        //先遍历到尾节点之前，循环外再遍历尾节点
            os << curr_ptr -> m_data << "-";
            curr_ptr = curr_ptr -> m_next;
        }
        os << curr_ptr -> m_data << "-";
    }
    os << "head" << std::endl;
    return os;
}
#endif /* DOUBLY_LINKED_LIST_H_ */
