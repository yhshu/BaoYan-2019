/**
4103:踩方格
查看 提交 统计 提示 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
有一个方格矩阵，矩阵边界在无穷远处。我们做如下假设：
a.    每走一步时，只能从当前方格移动一格，走到某个相邻的方格上；
b.    走过的格子立即塌陷无法再走第二次；
c.    只能向北、东、西三个方向走；
请问：如果允许在方格矩阵上走n步，共有多少种不同的方案。2种走法只要有一步不一样，即被认为是不同的方案。

输入
允许在方格上行走的步数n(n <= 20)
输出
计算出的方案数量
样例输入
2
样例输出
7
 */

#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 50;
int n;
int ans;
bool vis[maxn][maxn];

void init() {
    memset(vis, false, sizeof(vis));
}

/**
 * 计算方案数
 * @param i 当前横坐标
 * @param j 当前纵坐标
 * @param n 剩余步数
 * @return
 */
int ways(int i, int j, int n) {
    if (!n)  // 走完所有步数
        return 1;
    if(vis[i][j]) return 0;
    vis[i][j] = true;
    int ret = 0;
    if (!vis[i][j - 1])
        ret += ways(i, j - 1, n - 1);
    if (!vis[i][j + 1])
        ret += ways(i, j + 1, n - 1);
    if (!vis[i + 1][j])
        ret += ways(i + 1, j, n - 1);
    vis[i][j] = false;
    return ret;
}

int main() {
    while (cin >> n) {
        init();
        ans = ways(0, 25, n);
        cout << ans << endl;
    }
    return 0;
}
