/*
总时间限制: 1000ms 内存限制: 65536kB
描述
输入两个整数X和Y，输出两者之间的素数个数（包括X和Y）。

输入
两个整数X和Y（1 <= X,Y <= 105）。
输出
输出一个整数，表示X，Y之间的素数个数（包括X和Y）。
样例输入
1 100
样例输出
25
*/

#include <cmath>
#include <iostream>

#define MAXY 10010
using namespace std;
bool comp[MAXY]; // 合数为 true
int main() {
    int x, y;
    int res = 0;
    cin >> x >> y;
    // 埃式筛法
    int m = sqrt(y + 0.5);
    for (int i = 2; i < m; i++) {
        if (!comp[i]) { // 质数
            for (int j = i * i; j <= y; j += i)
                comp[j] = true;
        }
    }
    // 统计素数个数
    for (int i = x; i <= y; i++) {
        if (i != 1 && !comp[i]) // 注意 1 不是质数
            res++;
    }
    cout << res;
    return 0;
}
