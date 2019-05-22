/*
 * 8785:装箱问题
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
有一个箱子容量为V（正整数，0<=v<=20000），同时有n个物品（0< n<=30），每个物品有一个体积（正整数）。

要求n个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。

输入
第一行是一个整数V，表示箱子容量。
第二行是一个整数n，表示物品数。
接下来n行，每行一个正整数（不超过10000），分别表示这n个物品的各自体积。
输出
一个整数，表示箱子剩余空间。
样例输入
24
6
8
3
12
7
9
7
样例输出
0
来源
NOIP2001复赛 普及组 第四题
 */

#include <iostream>

using namespace std;

const int maxn = 40;
const int maxv = 20010; // 注意箱子容量的上限和物品数量的上限不同
int V, n; // 箱子容量和物品数量
int nums[maxn];
int dp[maxv];

int main() {
    cin >> V >> n;
    // 输入
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // 01 背包
    for (int i = 0; i < n; i++) {
        for (int j = V; j >= nums[i]; j--) {
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    cout << V - dp[V] << endl;
}
