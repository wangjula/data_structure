//
//  static_list.cpp
//  data_structure_learning
//
//  Created by 王久亮 on 2018/6/28.
//  Copyright © 2018年 王久亮. All rights reserved.
//
#ifndef STATIC_LIST_H_
#define STATIC_LIST_H_

#include <iostream>

/**
 * 静态表结点
 */
const int kMaxSize = 100;
template <class T>
struct Node {
    T data;
    int next;
};

/**
 * 静态表类
 */
template <class T>
class StaticList {
public:
    void InitList();                       //初始化静态链表
    void Output() const;                   //输出
    int Length() const;                    //计算链表长度
    int Search(const T & item) const;      //查找元素
    int Locate(int i) const;               //定位第i个结点
    bool Append(const T & item);           //在链表后添加一个结点
    bool Insert(int i, const T & item);    //在指定位置插入结点
    bool Remove(int i);                    //删除指定结点
    bool IsEmpty() const;                  //判空
private:
    Node<T> elems[kMaxSize];               //静态链表存储数组
    int next_avil;                         //下一次使用的序号
};

/**
 * 初始化静态链表
 */
template <class T>
void StaticList<T>::InitList() {
    elems[0].next = -1;                    //附加头结点
    next_avil = 1;
    for (int i = 1; i < kMaxSize - 1; ++ i) {
        elems[i].next = i + 1;
        
    }
    elems[kMaxSize - 1].next = -1;         //标志尾结点
};

/**
 * 输出元素
 */
template <class T>
void StaticList<T>::Output() const {
    int curr_ptr = elems[0].next;
    std::cout << "列表中元素为：" << std::endl;
    while (curr_ptr != -1) {
        std::cout << elems[curr_ptr].data << " ";
        curr_ptr = elems[curr_ptr].next;
    }
    std::cout << std::endl;
}

/**
 * 计算链表长度
 */
template <class T>
int StaticList<T>::Length() const {
    int count = 0;
    int curr_ptr = 0;
    while (elems[curr_ptr ++].next != -1) {
        ++ count;
    }
    return count;
};

/**
 * 查找元素
 */
template <class T>
int StaticList<T>::Search(const T & item) const {
    int curr_ptr = elems[0].next;          //从附加头结点顺序查找
    while (curr_ptr != -1) {
        if (elems[curr_ptr].data == item) {
            break;
        } else {
            curr_ptr = elems[curr_ptr].next;
        }
    }
    return curr_ptr;
};

/**
 * 定位第i个结点
 */
template <class T>
int StaticList<T>::Locate(int i) const {
    if (i < 0) {                          //不合理的i
        return -1;
    }
    if (i == 0) {
        return 0;
    }
    
    int count = 1;
    int curr_ptr = elems[0].next;
    while (curr_ptr != -1 && count < i) {
        curr_ptr = elems[curr_ptr].next;
        ++ count;
    }
    return curr_ptr;
};

/**
 * 在链表后添加结点
 */
template <class T>
bool StaticList<T>::Append(const T & item) {
    if (next_avil == -1) {                         //表满，插入数据失败
        return false;
    }
    
    int new_node_pos = next_avil;                  //加入新结点
    next_avil = elems[next_avil].next;             //修改next_avil
    elems[new_node_pos].data = item;
    elems[new_node_pos].next = -1;
    
    
    int curr_ptr = 0;                             //修改上个结点的next， 指向新结点
    while (elems[curr_ptr].next != -1) {
        curr_ptr = elems[curr_ptr].next;
    }
    elems[curr_ptr].next = new_node_pos;
    
    return true;
};

/**
 * 插入结点
 */
template <class T>
bool StaticList<T>::Insert(int i, const T & item) {
    if (next_avil == -1) {                        //表满， 插入失败
        return false;
    }
    
    int pos = Locate(i);
    if (pos != -1 && pos != 0) {                  //i有效才插入
        int new_node_pos = next_avil;
        next_avil = elems[next_avil].next;
        elems[new_node_pos].data = item;
        elems[new_node_pos].next = elems[pos].next;
        elems[pos].next = new_node_pos;
        return true;
    }
    return false;
};

/**
 * 删除结点
 */
template <class T>
bool StaticList<T>::Remove(int i) {
    int pre = Locate(i - 1);
    int pos = elems[pre].next;
    if (pre != -1 && pos != -1) {
        elems[pre].next = elems[pos].next;
        
        elems[pos].next = next_avil;           //使next_avil指向被删结点，用于下次分配
        next_avil = pos;
        return true;
    }
    return false;
};

/**
 * 判空
 */
template <class T>
bool StaticList<T>::IsEmpty() const {
    return elems[0].next == -1;
};
#endif /*STATIC_LIST_H_*/
