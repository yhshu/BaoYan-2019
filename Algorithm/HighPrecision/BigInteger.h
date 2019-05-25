//
// Created by 舒意恒 on 2019/5/25.
//

#ifndef BigInteger_H
#define BigInteger_H

#include <iostream>

using namespace std;

const int maxn = 1000;

class BigInteger {  // 长整数
public:
    int d[maxn];    // 存储长整数，d[0]是最低位
    int len;        // 记录长度

    /**
     * 必要的初始化
     * 设置长度为0，并清零长整数数组
     */
    void init();

    /**
     * 构造方法
     */
    BigInteger();

    /**
     * 构造方法
     * @param num int 型整数
     */
    BigInteger(int num);

    /**
     * 构造方法
     * @param str 表示长整数的字符串，str[0]是最高位，与长整数的存储相反
     */
    BigInteger(string str);

    /**
     * 去除前导0
     */
    void removeLeadingZeros();

    /**
     * 长整数加法
     * @param bigInteger 长整数
     * @return 两个长整数的和
     */
    BigInteger operator+(const BigInteger &bigInteger);

    /**
     * 长整数减法
     * @param bigInteger 长整数
     * @return 两个长整数的差
     */
    BigInteger operator-(const BigInteger &bigInteger);

    /**
     * 长整数乘法
     * @param num 乘数
     * @return 长整数与 int 型整数的积
     */
    BigInteger operator*(int num);

    /**
     * 长整数除法
     * @param divisor 除数
     * @param quotient 所得余数，以引用形式返回
     * @return 商
     */
    BigInteger operator/(int divisor, int &quotient);

    /**
     * 长整数比较
     * @param bigInteger 长整数
     * @return 大于返回1，等于返回0，小于返回-1
     */
    int compare(const BigInteger &bigInteger);
};

/**
 * 结果为长整数的指数运算
 * @param a 底数
 * @param n 指数
 * @return 计算结果
 */
BigInteger pow(int a, int n);

/**
 * 结果为长整数的阶乘运算
 * @param n 阶乘数
 * @return 阶乘结果
 */
BigInteger factorial(int n);

/**
 * 长整数到输出流
 * @param os 输出流
 * @param bigInteger 长整数
 * @return 包含长整数的输出流
 */
ostream &operator<<(ostream &os, const BigInteger &bigInteger);


#endif //BigInteger_H
