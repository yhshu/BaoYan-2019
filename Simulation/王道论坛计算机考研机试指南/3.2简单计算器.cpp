/*
题目描述:
读入一个只包含 +, -, *, / 的非负整数计算表达式,计算该表达式的值。
输入:
测试输入包含若干测试用例,每个测试用例占一行,每行不超过 200 个字符,
整数和运算符之间用一个空格分隔。没有非法表达式。当一行中只有 0 时输入结束,相应的结果不要输出。
输出:
对每个测试用例输出 1 行,即该表达式的值,精确到小数点后 2 位。
样例输入:
1 + 2
4 + 2 * 5 - 7 / 11
0
样例输出:
3.00
13.36
来源:
2006 年浙江大学计算机及软件工程研究生机试真题
*/

#include <cstring>
#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

int mat[][5] = {1, 0, 0, 0, 0,
                1, 0, 0, 0, 0,
                1, 0, 0, 0, 0,
                1, 1, 1, 0, 0,
                1, 1, 1, 0, 0};
// 优先级矩阵，若 mat[i][j] == 1 表示i号运算符优先级大于j号运算符
// 1号+，2号-，3号*，4号/
// 人为添加在表达式首尾的标记运算符为0号

char str[220]; // 保存表达式字符串
stack<int> op;    // 运算符栈，保存运算符编号
stack<double> in; // 数字栈，运算结果可能为浮点数

void getOp(bool &retOp, int &retNum, int &i) {
    // 获得表达式中下一个元素函数，若函数运行结束时，引用变量 retOp 为 true，
    // 则表示该元素为一个运算符，其编号保存在引用变量 retNum 中；否则，表示该元素
    // 为一个数字，其值保存在引用变量 retNum 中，引用变量 i 表示遍历到的字符串下标
    if (i == 0 && op.empty()) {
        // 此时遍历字符串第一个字符，且运算符栈为空，人为添加编号为0的标记字符
        retOp = true; // 返回为运算符
        retNum = 0;    // 编号为0
        return;
    }
    if (str[i] == '\0') { // 若此时遍历字符为空字符，则表示字符串已经被遍历完
        retOp = true; // 返回为运算符
        retNum = 0;    // 编号为0的标记字符
        return;
    }
    if (str[i] >= '0' && str[i] <= '9') { // 当前字符为数字
        retOp = false;                       // 返回为数字
    } else {                              // 否则为运算符
        retOp = true;                        // 返回为运算符
        switch (str[i]) {
            case '+':
                retNum = 1;
                break;
            case '-':
                retNum = 2;
                break;
            case '*':
                retNum = 3;
                break;
            case '/':
                retNum = 4;
                break;
            default:
                break;
        }
        i += 2; // 跳过该运算符及其之后的空格
        return;
    }
    retNum = 0;
    for (; str[i] != ' ' && str[i] != '\0'; i++) {
        // 若字符串未被遍历完，下一个字符不是空格
        // 则依次遍历其后数字，计算当前连续数字字符表示的数值
        retNum *= 10;
        retNum += str[i] - '0';
    }
    if (str[i] == ' ') // 其后字符为空格，表示字符串未被遍历完
        i++;
}

int main() {
    while (gets(str)) { // scanf 遇到空格停止，gets 能读取一行带空格字符串
        if (str[0] == '0' && str[1] == 0) // 输入只有一个0
            break;
        bool retOp; // 返回的运算符
        int retNum; // 返回的数字
        int idx = 0;
        while (!op.empty()) // 清空运算栈
            op.pop();
        while (!in.empty()) // 清空数字栈
            in.pop();
        while (true) {               // 循环遍历表达式字符串
            getOp(retOp, retNum, idx); // 获取表达式中下一个元素
            if (!retOp) {      // 该元素为数字
                in.push((double) retNum);
            } else {            // 该元素非数字
                double tmp = 0;
                if (op.empty() || mat[retNum][op.top()] == 1) {
                    op.push(retNum);
                }
                    // 若运算符堆栈为空或当前遍历到的运算符优先级大于栈顶运算符，将该运算符压入运算符堆栈
                else { // 否则
                    while (mat[retNum][op.top()] == 0) {
                        // 只要当前运算符优先级小于栈顶元素运算符，则重复循环
                        int ret = op.top();
                        op.pop();
                        double b = in.top();
                        in.pop();
                        double a = in.top();
                        in.pop();
                        // 从数字堆栈栈顶弹出两个数字
                        switch (ret) {
                            case 1:
                                tmp = a + b;
                                break;
                            case 2:
                                tmp = a - b;
                                break;
                            case 3:
                                tmp = a * b;
                                break;
                            case 4:
                                tmp = a / b;
                                break;
                            default:
                                break;
                        }
                        in.push(tmp);
                    }
                    op.push(retNum);
                }
            }
            if (op.size() == 2 && op.top() == 0)
                break;
            // 若运算符堆栈只有两个元素，且其栈顶元素为标记运算符，则表示表达式求值结束
        }
        printf("%.2f\n", in.top());
    }
    return 0;
}
