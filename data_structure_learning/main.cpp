//
//  main.cpp
//  data_structure_learning
//
//  Created by 王久亮 on 2018/5/9.
//  Copyright © 2018年 王久亮. All rights reserved.
//

#include <iostream>
#include "linear_list.hpp"

int main(int argc, const char * argv[]) {
    using std::cout;
    using std::endl;
    using std::cin;
    
    SeqList<int> list(5);
    list.input();
    list.output();
    
    int i;
    int item;
    
    cout << "测试删除元素，请输入需要删除的元素序号（从1开始计数）：\n";
    cin >> i;
    if (list.Remove(i, item)) {
        cout << "删除成功" << endl;
        cout << "被删除的元素为：" << item << endl;
        list.output();
    }
    
    cout << "测试插入元素，请输入元素序号i和需要插入的元素item（i从1开始计数，item将插入到i之后）：\n";
    cin >> i >> item;
    if (list.InsertBack(i, item)) {
        cout << "插入元素成功" << endl;
        cout << list << endl;
    }
    return 0;
}
