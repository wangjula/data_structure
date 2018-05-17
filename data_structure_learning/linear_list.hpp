//
//  linear_list.hpp
//  data_structure_learning
//
//  Created by 王久亮 on 2018/5/9.
//  Copyright © 2018年 王久亮. All rights reserved.
//

/*线性表*/
#ifndef LINEAR_LIST_H_
#define LINEAR_LIST_H_

#include <iostream>
#include <cstdlib>

/**
 * 线性表基类
 */
template <class T>
class LinearList {
public:
    //构造析构
    LinearList() {};                                                    //构造函数
    virtual ~LinearList() {};                                           //析构函数
    LinearList(const LinearList & list);                                //复制构造函数
    LinearList & operator=(const LinearList & list);                    //复制赋值运算符
    LinearList(LinearList && list);                                     //移动构造函数
    LinearList & operator=(LinearList && list);                         //移动赋值运算符
    
    //成员函数
    virtual int Size() const = 0;                                       //表体积
    virtual int Length() const = 0;                                     //表长
    virtual int Search(const T & item) const = 0;                       //查找指定元素位置
    virtual int Locate(int i) const = 0;                                //返回第i个元素的位置，如果在范围内，返回i,否则返回0
    virtual bool getData(int i, T & item) const = 0;                    //将第i个元素复制给item
    virtual bool setData(int i, T & item) = 0;                          //将第i个元素设置为item
    virtual bool InsertBack(int i, const T & item) = 0;                 //将item插入到i后
    virtual bool Remove(int i, T & item) = 0;                           //删除第i个元素，并将元素复制给item
    virtual bool IsEmpty() const = 0;                                   //判断是否表空
    virtual bool IsFull() const = 0;                                    //判断是否表满
    virtual void Sort() = 0;                                            //对表排序
    virtual void input() = 0;                                           //输入
    virtual void output() = 0;                                          //输出
    
    //友元
    friend std::ostream & operator<<(std::ostream & os,                 //重载操作符<<
                                     const LinearList & list);
};

#endif /* LINEAR_LIST_H_ */
