//
//  Josephus.cpp
//  data_structure_learning
//
//  Created by 王久亮 on 2018/5/17.
//  Copyright © 2018年 王久亮. All rights reserved.
//

#include <iostream>
#include <cstdlib>

/**
 * 约瑟夫环类（无附加节点）
 */
template <class T>
class Josephus {
public:
    Josephus(int n, int m, int i = 1);
    virtual ~Josephus();
    void Input();
    void Insert(const T & item);
    void MakeEmpty();
    void Run();
    bool IsEmpty() const;
private:
    class Node {
    public:
        T m_data;
        Node * m_next;
        Node(Node * next = nullptr) : m_next(next) {}
        Node(T data, Node * next = nullptr) : m_data(data), m_next(next) {}
    };
    Node * head;
    Node * rear;
    int m_people_size;
    int m_count_num;
    int m_start_i;
    Node * MoveTo(Node * curr_ptr, int step);
};

/**
 * 构造函数
 * n：总人数 m：报数值 i：从第i个开始
 */
template <class T>
Josephus<T>::Josephus(int n, int m, int i) {
    if (n < 1 || m < 1 || i < 1) {
        std::cerr << "输出参数有误，无法建立约瑟夫环";
        exit(EXIT_FAILURE);
    }
    m_people_size = n;
    m_count_num = m;
    m_start_i = i;
    head = rear = nullptr;
    Input();
}

/**
 * 析构函数
 */
template <class T>
Josephus<T>::~Josephus() {
    MakeEmpty();
}

/**
 * 置空
 */
template <class T>
void Josephus<T>::MakeEmpty() {
    if (head != nullptr) {
        Node * curr_ptr = head;
        Node * del_ptr;
        while (curr_ptr -> m_next != head) {
            del_ptr = curr_ptr -> m_next;
            curr_ptr -> m_next = del_ptr -> m_next;
            delete del_ptr;
        }
    }
}

/**
 * 对<int>参数类型具体化输入
 */
template <>
void Josephus<int>::Input() {
    for (int i = 1; i <= m_people_size; ++ i) {
        Insert(i);
    }
}

/**
 * 输入
 */
template <class T>
void Josephus<T>::Input() {
    std::cout << "开始建立约瑟夫环，请依次输入元素：";
    T item;
    for (int i = 0; i < m_people_size; ++ i) {
        std::cin >> item;
        Insert(item);
    }
}

/**
 * 插入节点
 */
template <class T>
void Josephus<T>::Insert(const T & item) {
    Node * new_node = new Node(item);
    if (head == nullptr) {
        head = rear = new_node;
        rear -> m_next = head;
    } else {
        new_node -> m_next = rear -> m_next;
        rear -> m_next = new_node;
        rear = new_node;
    }
}

/**
 * 判断约瑟夫环为空
 */
template <class T>
bool Josephus<T>::IsEmpty() const {
    return head == nullptr;
}

/**
 * 约瑟夫环问题仿真
 */
template <class T>
void Josephus<T>::Run() {
    if (IsEmpty()) {
        std::cerr << "约瑟夫环为空，退出";
        exit(EXIT_FAILURE);
    }
    Node * curr_ptr = head;
    Node * pre_ptr = nullptr;
    for (int i = 1; i < m_start_i; ++ i) {
        pre_ptr = curr_ptr;
        curr_ptr = curr_ptr -> m_next;
    }
    
    T item;
    while (rear != head) {
        for (int i = 0; i < m_count_num; ++ i) {
            pre_ptr = curr_ptr;
            curr_ptr = curr_ptr -> m_next;
        }
        if (curr_ptr == rear) {
            rear = pre_ptr;
        }
        if (curr_ptr == head) {
            head = curr_ptr -> m_next;
        }
        pre_ptr -> m_next = curr_ptr -> m_next;
        item = curr_ptr -> m_data;
        std::cout << "本次出列：" << item << std::endl;
        delete curr_ptr;
    }
    
    std::cout << "出列完毕" << std::endl;
    std::cout << "剩余节点为：" << head -> m_data << std::endl;
}

//int main() {
//    Josephus<int> list(20, 3, 2);
//    list.Run();
//}

