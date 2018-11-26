#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

char str[220]; // 保存表达式字符串
int mat[][5] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
                0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0};
// 优先级矩阵，若 mat[i][j] == 1 表示i号运算符优先级大于j号运算符
// 1号+，2号-，3号*，4号/
// 人为添加在表达式首尾的标记运算符为0号
stack<int> op;    // 运算符栈，保存运算符编号
stack<double> in; // 数字栈，运算结果可能为浮点数
void getOp(bool &reto, int &retn, int &i) {
  // 获得表达式中下一个元素函数，若函数运行结束时，引用变量 reto 为
  // true，则表示该元素为一个运算符，其编号保存在引用变量 retn
  // 中；否则，表示该元素为一个数字，其值保存在引用变量 retn 中，引用变量 i
  // 表示遍历到的字符串下标
  if (i == 0 && op.empty() == true) {
    // 此时遍历字符串第一个字符，且运算符栈为空，人为添加编号为0的标记字符
    reto = true; // 为运算符
    retn = 0;    // 编号为0
    return;
  }
  if (str[i] == 0) { // 若此时遍历字符为空字符，则表示字符串已经被遍历完
    reto = true; // 返回为运算符
    retn = 0;    // 编号为0的标记字符
    return;
  }
  if (str[i] >= '0' && str[i] <= '9') { // 当前字符为数字
    reto = false;                       // 返回为数字
  } else {                              // 否则为运算符
    reto = true;                        // 返回为运算符
    switch (str[i]) {
    case '+':
      retn = 1;
      break;
    case '-':
      retn = 2;
      break;
    case '*':
      retn = 3;
      break;
    case '/':
      retn = 4;
      break;
    }
    i += 2; // 跳过该运算符及其之后的空格
    return;
  }
  retn = 0;
  for (; str[i] != ' ' && str[i] != 0; i++) {
    // 若字符串未被遍历完，下一个字符不是空格，则依次遍历其后数字，计算当前连续数字字符表示的数值
    retn *= 10;
    retn += str[i] - '0';
  }
  if (str[i] == ' ') // 其后字符为空格，表示字符串未被遍历完
    i++;
  return;
}

int main() {
  while (gets(str)) {                 // scanf 遇到空格停止
    if (str[0] == '0' && str[1] == 0) // 输入只有一个0
      break;
    bool retop; // 返回的运算符
    int retnum; // 返回的数字
    int idx = 0;
    while (!op.empty()) // 清空运算栈
      op.pop();
    while (!in.empty()) // 清空数字栈
      in.pop();
    while (true) {               // 循环遍历表达式字符串
      getOp(retop, retnum, idx); // 获取表达式中下一个元素
      if (retop == false) {      // 该元素为数字
        in.push((double)retnum);
      } else { // 该元素非数字
        double tmp;
        if (op.empty() == true || mat[retnum][op.top()] == 1) {
          op.push(retnum);
        }
        // 若运算符堆栈为空或当前遍历到的运算符优先级大于栈顶运算符，将该运算符压入运算符堆栈
        else { // 否则
          while (mat[retnum][op.top()] == 0) {
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
          op.push(retnum);
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
