//
//  polynomial.cpp
//  data_structure_learning
//
//  Created by 王久亮 on 2018/5/18.
//  Copyright © 2018年 王久亮. All rights reserved.
//
#include <cmath>
#include "polynomial.hpp"
/**
 * 构造函数
 */
Polynomial::Polynomial() {
    rear = head = new Term;
}

/**
 * 复制构造函数
 */
Polynomial::Polynomial(const Polynomial & p) {
    rear = head = new Term;
    Term * p_ptr = p.head -> m_next;
    while (p_ptr != nullptr) {
        Term * new_term = new Term(p_ptr -> m_coef, p_ptr -> m_exp);
        new_term -> m_next = rear -> m_next;
        rear -> m_next = new_term;
        rear = new_term;
    }
}

/**
 * 析构函数
 */
Polynomial::~Polynomial() {
    MakeEmpty();
}

/**
 * 获取多项式最大阶数
 */
int Polynomial::MaxOrder() const {
    if (rear != head) {
        return rear -> m_exp;
    }
    return 0;
}

/**
 * 插入多项式节点
 */
bool Polynomial::Insert(float coef, int exp) {
    if (head == nullptr) {
        rear = head = new Term;
    }
    Term * new_term = new Term(coef, exp);
    new_term -> m_next = rear -> m_next;
    rear -> m_next = new_term;
    rear = new_term;
    return true;
}

/**
 * 多项式置空
 */
void Polynomial::MakeEmpty() {
    if (head != nullptr) {
        Term * del_ptr = head -> m_next;
        while (del_ptr != nullptr) {
            head -> m_next = del_ptr -> m_next;
            delete del_ptr;
            del_ptr = head -> m_next;
        }
        delete head;
    }
}

/**
 * 输出多项式信息
 */
std::ostream & operator<<(std::ostream & os, const Polynomial & p) {
    Polynomial::Term * curr_ptr = p.head -> m_next;
    os << "多项式为：";
    while (curr_ptr != nullptr) {
        switch (curr_ptr -> m_exp) {
            case 0:
                os << curr_ptr -> m_coef;
                break;
            case 1:
                os << curr_ptr -> m_coef << "X";
                break;
            default:
                os << curr_ptr -> m_coef << "X^" << curr_ptr -> m_exp;
                break;
        }
        if (curr_ptr != p.rear) {
            os << "+";
        }
        curr_ptr = curr_ptr -> m_next;
    }
    os << std::endl;
    return os;
}

/**
 * 输入建立多项式
 */
std::istream & operator>>(std::istream & is, Polynomial & p) {
    std::cout << "开始建立多项式, 依次输入系数 指数（0 0结束输出): " << std::endl;
    float coef;
    int exp;
    is >> coef >> exp;
    while (fabs(coef) >= 1e-5 || exp != 0) {
        p.Insert(coef, exp);
        is >> coef >> exp;
    }
    return is;
}

/**
 * 多项式相加（两多项式不能为空）
 */
Polynomial operator+(const Polynomial & p1, const Polynomial & p2) {
    Polynomial result;
    Polynomial::Term * p1_curr_ptr = p1.head -> m_next;
    Polynomial::Term * p2_curr_ptr = p2.head -> m_next;
    float new_coef;
    while (p1_curr_ptr != nullptr && p2_curr_ptr != nullptr) {             //逐项比较p1, p2中的项，将指数小的项加入，至其中一个多项式完全加入
        if (p1_curr_ptr -> m_exp == p2_curr_ptr -> m_exp) {
            new_coef = p1_curr_ptr -> m_coef + p2_curr_ptr -> m_coef;
            if (fabs(new_coef) > 0.001) {
                result.Insert(new_coef, p1_curr_ptr -> m_exp);
            }
            p1_curr_ptr = p1_curr_ptr -> m_next;
            p2_curr_ptr = p2_curr_ptr -> m_next;
        } else if (p2_curr_ptr -> m_exp < p1_curr_ptr -> m_exp) {
            result.Insert(p2_curr_ptr -> m_coef, p2_curr_ptr -> m_exp);
            p2_curr_ptr = p2_curr_ptr -> m_next;
        } else {
            result.Insert(p1_curr_ptr -> m_coef, p1_curr_ptr -> m_exp);
            p1_curr_ptr = p1_curr_ptr -> m_next;
        }
    }
    
    Polynomial::Term * temp_ptr = nullptr;                                  //将剩余的多项式逐项加入
    if (p1_curr_ptr != nullptr) {
        temp_ptr = p1_curr_ptr;
    } else {
        temp_ptr = p2_curr_ptr;
    }
    
    while (temp_ptr != nullptr) {
        result.Insert(temp_ptr -> m_coef , temp_ptr -> m_exp);
        temp_ptr = temp_ptr -> m_next;
    }
    return result;
}

/**
 * 多项式相乘（两多项式不能为空）
 */
Polynomial operator*(const Polynomial & p1, const Polynomial & p2) {
    int max_exp = p1.MaxOrder() + p2.MaxOrder();
    float * coefs = new float[max_exp + 1];                               //辅助数组，存储乘法计算结果的系数
    for (int i = 0; i < max_exp + 1; ++ i) {
        coefs[i] = 0.0f;
    }
    
    Polynomial::Term * p1_curr_ptr = p1.head -> m_next;
    Polynomial::Term * p2_curr_ptr;
    while (p1_curr_ptr != nullptr) {
        p2_curr_ptr = p2.head -> m_next;
        while (p2_curr_ptr != nullptr) {
            coefs[p1_curr_ptr -> m_exp + p2_curr_ptr -> m_exp]
                += p1_curr_ptr -> m_coef * p2_curr_ptr -> m_coef;
            p2_curr_ptr = p2_curr_ptr -> m_next;
        }
        p1_curr_ptr = p1_curr_ptr -> m_next;
    }

    Polynomial result;
    for (int i = 0; i < max_exp + 1; i ++) {
        if (fabs(coefs[i]) > 0.001) {
            result.Insert(coefs[i], i);
        }
    }
    delete [] coefs;
    return result;
}
