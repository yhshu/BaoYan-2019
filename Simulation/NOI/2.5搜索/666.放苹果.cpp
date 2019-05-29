/**
 * 1664:放苹果
查看 提交 统计 提示 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
输入
第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
输出
对输入的每组数据M和N，用一行输出相应的K。
样例输入
1
7 3
样例输出
8
来源
lwx@POJ
 */

#include <iostream>

using namespace std;

int ans;

/**
 * 放苹果搜索
 * @param start 至少放置的苹果数，去掉重复放法
 * @param m 苹果数
 * @param n 盘子数
 */
void dfs(int start, int m, int n) {
//    cout << "DFS: " << num << " " << primeNum << endl;
    if (n == 0 || m == 0) {
        if (n == 0 && m == 0)
            ans++;
        return;
    }

    // 本盘子可以放 start～m 个苹果
    for (int i = start; i <= m; i++) {
        dfs(i, m - i, n - 1);
    }
}

int main() {
    int T;
    cin >> T;
    int m, n;
    while (T--) {
        ans = 0;
        cin >> m >> n;
        dfs(0, m, n);
        cout << ans << endl;
    }
    return 0;
}
