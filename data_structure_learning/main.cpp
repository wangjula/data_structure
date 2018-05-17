//
//  main.cpp
//  data_structure_learning
//
//  Created by 王久亮 on 2018/5/9.
//  Copyright © 2018年 王久亮. All rights reserved.
//

#include <iostream>
#include "seq_list.hpp"
#include "linked_list.hpp"

/*求顺序表并集*/
template <class T>
SeqList<T> & union_list(SeqList<T> & la, const SeqList<T> & lb);

/*求顺序表交集*/
template <class T>
SeqList<T> & intersaction_list(SeqList<T> & la, const SeqList<T> & lb);


int main(int argc, const char * argv[]) {
    using std::cout;
    using std::endl;
    using std::cin;
    
//    SeqList<int> list(5);
//    list.input();
//    list.output();
//
//    int i;
//    int item;
//
//    cout << "测试删除元素，请输入需要删除的元素序号（从1开始计数）：\n";
//    cin >> i;
//    if (list.Remove(i, item)) {
//        cout << "删除成功" << endl;
//        cout << "被删除的元素为：" << item << endl;
//        list.output();
//    }
//
//    cout << "测试插入元素，请输入元素序号i和需要插入的元素item（i从1开始计数，item将插入到i之后）：\n";
//    cin >> i >> item;
//    if (list.InsertBack(i, item)) {
//        cout << "插入元素成功" << endl;
//        cout << list << endl;
//    }
    
    /*测试La与Lb合并，求交集，结果放置到La*/
//    SeqList<int> la(20);
//    cout << "输入La元素信息：\n";
//    la.input();
//    cout << "La中元素信息为：\n";
//    la.output();
//    SeqList<int> lb(10);
//    cout << "输入Lb元素信息：\n";
//    lb.input();
//    cout << "Lb中元素信息为：\n";
//    lb.output();
////    cout <<"合并后La中元素信息为：\n";
////    union_list(la, lb);
//    cout << "求交集结果为：\n";
//    intersaction_list(la, lb);
//    la.output();
    
    /*测试单链表*/
    LinkedList<int> list;
    list.InputFront();
    list.Output();
    cout << endl;
    cout << "插入一个节点：" << endl;
    int item;
    cin >> item;
    if (list.InsertBack(1, item)) {
        cout << "插入成功：" << endl;
        list.Output();
        cout << endl;
    }
    cout << "元素长度为：" << list.Length() << endl;
    cout << "删除第1个元素，删除后：" << endl;
    list.Remove(1);
    list.Output();
    cout << endl;
    
//    LinkedList<char> c_list;
//    c_list.InputRear();
//    c_list.Output();
//    cout << endl;
    
    return 0;
}

/*求顺序表并集*/
template <class T>
SeqList<T> & union_list(SeqList<T> & la, const SeqList<T> & lb) {
    int length_a = la.Length();
    int length_b = lb.Length();
    if (la.Size() < length_a + length_b) {
        std::cerr << "La长度过短，无法容纳合并的结果" << std::endl;
        exit(EXIT_FAILURE);
    }
    T item;
    int i = 1;
    while (i <= length_b) {
        lb.getData(i, item);
        if (la.Search(item) == 0) {
            la.InsertBack(length_a ++, item);
        }
        ++ i;
    }
    return la;
}

template <class T>
SeqList<T> & intersaction_list(SeqList<T> & la, const SeqList<T> & lb) {
    int length_a = la.Length();
    int length_b = lb.Length();
    if (length_b > la.Size()) {
        std::cerr << "La长度过短，无法容纳求交集的结果" << std::endl;
        exit(EXIT_FAILURE);
    }
    T item;
    int i = 1;
    while (i <= length_a) {
        la.getData(i, item);
        if (lb.Search(item)) {
            ++ i;
        } else {
            la.Remove(i, item);
            -- length_a;
        }
    }
    return la;
}
