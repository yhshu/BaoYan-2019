/*
总时间限制: 1000ms 内存限制: 65536kB
描述
用一个n*m的二维数组表示地图，1表示陆地，0代表海水，每一格都表示一个1*1的区域。地图中的格子只能横向或者纵向连接（不能对角连接），连接在一起的陆地称作岛屿，同时整个地图都被海水围绕。假设给出的地图中只会有一个岛屿，并且岛屿中不会有湖（即不会有水被陆地包围的情况出现）。请判断所给定的二维地图中岛屿的周长。

输入
第一行为n和m，表示地图的大小(1<=n<=100,
1<=m<=100)。接下来n行，每行有m个数，分别描述每一格的数值。数值之间均用空格隔开。
输出
只有一行，即岛屿的周长（正整数）。
样例输入
3 4
1 1 1 0
0 1 0 0
1 1 0 0
样例输出
14
来源
cs10116 final exam
*/

#include <iostream>

using namespace std;
#define MAXN 110
int n, m;
int res; // 输出的周长
int map[MAXN][MAXN];

void check(int i, int j) {
    if (map[i][j] == 0)
        return;
    if (i == 0 || i == n - 1)
        res++;
    if (j == 0 || j == m - 1)
        res++;
    if (i < n - 1 && map[i + 1][j] == 0)
        res++;
    if (j < m - 1 && map[i][j + 1] == 0)
        res++;
    if (i > 0 && map[i - 1][j] == 0)
        res++;
    if (j > 0 && map[i][j - 1] == 0)
        res++;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            check(i, j);
        }
    }
    cout << res;
    return 0;
}
