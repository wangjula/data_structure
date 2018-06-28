//
//  test_static_list.c
//  data_structure_learning
//
//  Created by 王久亮 on 2018/6/28.
//  Copyright © 2018年 王久亮. All rights reserved.
//

#include <iostream>
#include "../data_structure_learning/static_list.hpp"

int main() {
    using std::cout;
    using std::cin;
    using std::endl;
    
    StaticList<int> list;
    list.InitList();
    cout << "请输入元素(输入-1结束): ";
    int ch;
    cin >> ch;
    while (ch != -1) {
        list.Append(ch);
        cin >> ch;
    }
    list.Output();
    cout << "列表长度为：" << list.Length();
    cout << "开始删除元素：" << endl;
    list.Remove(2);
    list.Output();
    cout << "开始插入元素：" << endl;
    list.Insert(2, 5);
    list.Output();
}
