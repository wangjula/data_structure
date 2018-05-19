//
//  polynomial.hpp
//  data_structure_learning
//
//  Created by 王久亮 on 2018/5/18.
//  Copyright © 2018年 王久亮. All rights reserved.
//

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>

/**
 * 多项式类（按指数从小到大排列）
 */
class Polynomial {
public:
    //构造析构
    Polynomial();
    Polynomial(const Polynomial & p);
    virtual ~Polynomial();
    
    //成员函数
    int MaxOrder() const;
    bool Insert(float coef, int exp);
    void MakeEmpty();
    
    //友元
    friend std::ostream & operator<<(std::ostream & os, const Polynomial & p);
    friend std::istream & operator>>(std::istream & is, Polynomial & p);
    friend Polynomial operator+(const Polynomial & p1, const Polynomial & p2);
    friend Polynomial operator*(const Polynomial & p1, const Polynomial & p2);
private:
    class Term {
    public:
        float m_coef;                                       //多项式系数
        int m_exp;                                          //多项式指数
        Term * m_next;
        Term(float coef, int exp ,
             Term * next = nullptr) : m_coef(coef), m_exp(exp), m_next(next) {}
        Term(Term * next = nullptr) : m_next(next) {}
    };
    Term * head;
    Term * rear;
};

#endif /* POLYNOMIAL_H_ */
