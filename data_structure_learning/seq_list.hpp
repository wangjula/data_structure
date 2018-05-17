//
//  seq_list.hpp
//  data_structure_learning
//
//  Created by 王久亮 on 2018/5/13.
//  Copyright © 2018年 王久亮. All rights reserved.
//

#ifndef SEQ_LIST_H_
#define SEQ_LIST_H_

#include "linear_list.hpp"

/**
 * 顺序表类
 */
template <class T>
class SeqList : public LinearList<T> {
private:
    enum {DEFAULT_SIZE = 100};
    T * data;                                                           //存储顺序表元素的数组
    int max_size;                                                       //顺序表的容量
    int last_index = -1;                                                //当前已存元素的最后位置
    void resize(int new_size);                                          //重新设置顺序表容量大小
public:
    //构造析构
    explicit SeqList(int size = DEFAULT_SIZE);                          //构造函数
    SeqList(const SeqList & list);                                      //复制构造函数
    virtual ~SeqList();                                                 //析构函数
    SeqList & operator=(const SeqList & list);                          //复制赋值运算符
    SeqList(SeqList && list);                                           //移动构造函数
    SeqList & operator=(SeqList && list);                               //移动赋值运算符
    
    //成员函数
    virtual int Size() const override {return max_size;}                //返回顺序表的最大容量
    virtual int Length() const override {return last_index + 1;}        //线性表元素个数
    virtual int Search(const T & item) const override;                  //查找元素
    virtual int Locate(int i) const override;                           //定位第i个元素的位置，不在有效范围则返回-1
    virtual bool getData(int i, T & item) const override;               //获取指定位置的元素，复制给item
    virtual bool setData(int i, T & item) override;                     //将第i个元素设置为item
    virtual bool InsertBack(int i, const T & item) override;            //在i后插入item
    virtual bool Remove(int i, T & item) override;                      //删除第i个元素，并将其值复制给item
    virtual bool IsEmpty() const override {return last_index == -1;}    //判断表空
    virtual bool IsFull() const override {
        return  last_index == max_size -1;}                             //判断表满
    virtual void Sort() override;                                       //对表排序，输入输出
    virtual void input() override;                                      //输入
    virtual void output() override;                                     //输出
    
    //友元
    template <class U>
    friend std::ostream & operator<<(std::ostream & os,                 //重载操作符<<
                                     const SeqList<U> & list);
};


//***********************************************实现部分***********************************************

/**
 * 检测内存分配失败
 */
template <class T>
inline void check_alloc(const T & data) {
    if (data == nullptr) {
        std::cerr << "分配内存失败" << std::endl;
        exit(EXIT_FAILURE);
    }
}

//构造析构

/**
 * 构造函数
 */
template <class T>
SeqList<T>::SeqList(int sz) {
    if (sz <= 0) {
        std::cerr << "SeqList容量必须大于0" << std::endl;
        exit(EXIT_FAILURE);
    }
    max_size = sz;
    data = new (std::nothrow) T[max_size];
    check_alloc(data);
    last_index = -1;
}

/**
 * 复制构造函数
 */
template <class T>
SeqList<T>::SeqList(const SeqList<T> & seq_list) {
    max_size = seq_list.max_size;
    data = new (std::nothrow) T[max_size];
    check_alloc(data);
    last_index = -1;
    
    //逐个复制元素
    T value;
    for (int i = 1; i <= seq_list.last_index + 1; ++ i) {
        seq_list.getData(i, value);
        data[i - 1] = value;
        ++ last_index;
    }
}

/**
 * 析构函数
 */
template <class T>
SeqList<T>::~SeqList<T>() {
    delete [] data;
}

/**
 * 重载复制赋值操作符
 */
template <class T>
SeqList<T> & SeqList<T>::operator=(const SeqList<T> & seq_list) {
    if (this == &seq_list) {
        return *this;
    }
    delete [] data;
    max_size = seq_list.max_size;
    data = new (std::nothrow) T[max_size];
    check_alloc(data);
    last_index = -1;
    
    //逐个复制元素
    T value;
    for (int i = 1; i <= seq_list.last_index + 1; ++ i) {
        seq_list.getData(i, value);
        data[i - 1] = value;
        ++ last_index;
    }
}

/**
 * 移动构造函数
 */
template <class T>
SeqList<T>::SeqList(SeqList<T> && seq_list) {
    max_size = seq_list.max_size;
    last_index = seq_list.last_index;
    data = seq_list.data;
    seq_list.data = nullptr;
}

/**
 * 重载移动赋值操作符
 */
template <class T>
SeqList<T> & SeqList<T>::operator=(SeqList<T> &&seq_list) {
    if (this == &seq_list) {
        return *this;
    }
    delete [] data;
    max_size = seq_list.max_size;
    last_index = seq_list.last_index;
    data = seq_list.data;
    seq_list.data = nullptr;
    return *this;
}

/**
 * 在表中查找元素，如果找到就返回i (i从1开始计算)
 */
template <class T>
int SeqList<T>::Search(const T &item) const {
    for (int i = 0; i < last_index + 1; ++ i) {
        if (item == data[i]) {
            return i + 1;
        }
    }
    return 0;
}

/**
 * 定位第i个元素位置，如果在范围内返回i，否则返回0
 */
template <class T>
int SeqList<T>::Locate(int i) const {
    if (i > 0 && i <= last_index + 1) {
        return i;
    }
    return 0;
}

/**
 * i在有效范围内，将对应元素复制个item，返回true，否则返回false
 */
template <class T>
bool SeqList<T>::getData(int i, T &item) const {
    if (i > 0 && i <= last_index + 1) {
        item = data[i - 1];
        return true;
    }
    return false;
}

/**
 * i在有效范围内，将对应元素设置为item，返回true，否则返回false
 */
template <class T>
bool SeqList<T>::setData(int i, T &item) {
    if (i > 0 && i <= last_index - 1) {
        data[i - 1] = item;
        return true;
    }
    return false;
}

/**
 * 将item插入到第i个元素后面
 */
template <class T>
bool SeqList<T>::InsertBack(int i, const T &item) {
    if (IsFull()) {
        std::cerr << "表满， 添加元素失败" << std::endl;
        return false;
    }
    
    //第i个元素之后的元素复制后移
    for (int rear = last_index; rear >= i; -- rear) {
        data[rear + 1] = data[rear];
    }
    data[i] = item;
    ++ last_index;
    return true;
}

template <class T>
bool SeqList<T>::Remove(int i, T &item) {
    if (i <= 0 || i > last_index + 1) {
        std::cerr << "给定i不在有效范围内，删除元素失败" << std::endl;
        return false;
    }
    
    item = data[i - 1];
    
    //依次覆盖第i个及后面的元素
    for (int index = i - 1; index < last_index; ++ index) {
        data[index] = data[index + 1];
    }
    -- last_index;
    return true;
}

/**
 * 排序，暂不实现
 */
template <class T>
void SeqList<T>::Sort() {}

/**
 * 输入元素建立顺序表
 */
template <class T>
void SeqList<T>::input() {
    using std::cout;
    using std::endl;
    using std::cerr;
    using std::cin;
    cout << "开始建立顺序表，请输入顺序表中元素个数：" << endl;
    int length;
    char ch;
    while (!(cin >> length) || (length <= 0 || length > max_size)) {
        cerr << "必须输入1-" << max_size << "之间的数字:"  << endl;
        cin.clear();                                            //重置输入流
        while ((ch = cin.get())!='\n') {
            continue;
        }
    }
    last_index = length - 1;
    cout << "开始输入数据元素: " << endl;
    for (int i = 0; i < length; ++ i) {
        cin >> data[i];
    }
}

/**
 * 输出顺序表中的内容
 */
template <class T>
void SeqList<T>::output() {
    std::cout << "元素最后的下标为: " << last_index << std::endl;
    for (int i = 0; i <= last_index; ++ i) {
        std::cout << "#" << i + 1 << ": " << data[i] << std::endl;
    }
}

template <class T>
std::ostream & operator<<(std::ostream & os, const SeqList<T> & seq_list) {
    os << "元素最后的下标为: " << seq_list.last_index << "\n";
    for (int i = 0; i <= seq_list.last_index; ++ i) {
        os << "#" << i + 1 << ": " << seq_list.data[i] << "\n";
    }
    return os;
}

#endif /* SEQ_LIST_H_ */
