/*
样例输入：
)(rttyy())sss)(

样例输出：
)(rttyy())sss)(
?            ?$
*/

#include <iostream>
#include <stack>

using namespace std;
stack<int> S;                               // 用于存储左括号，遍历到左括号时入栈，遍历到右括号时出栈
char str[110];                              // 输入字符串
char ans[110];                              // 输出字符串
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while (cin >> str) {                    // 输入字符串
        for (int i = 0; str[i] != 0; i++) { // 从左到右遍历字符串
            if (str[i] == '(')              // 遇到左括号
            {
                S.push(i);                  // 将左括号下标压入栈中
                ans[i] = ' ';               // 暂时填充空格
            } else if (str[i] == ')') {     // 遇到右括号
                if (!S.empty()) {           // 堆栈非空
                    S.pop();                // 栈顶的左括号与其匹配，弹栈
                    ans[i] = ' ';
                } else
                    ans[i] = '?';           // 堆栈为空，无法找到左括号与其匹配，修改输出
            } else
                ans[i] = ' ';               // 其他字符，与括号匹配无关
        }
        while (!S.empty()) {                // 检查堆栈中遗留的左括号
            ans[S.top()] = '$';
            S.pop();
        }
        cout << str << '\n' << ans << '\n';
    }
    return 0;
}
