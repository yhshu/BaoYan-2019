//
// Created by Yiheng Shu on 2019/9/18.
//

#include <iostream>
#include <cstdio>

using namespace std;

int n;
const int maxn = 35;
int board[maxn][maxn];

void dfs(int x, int y) {
    if (board[x][y] > 1)
        board[x][y] = 0;
    else return;

    if (x - 1 >= 0 && board[x - 1][y] > 1)
        dfs(x - 1, y);
    if (x + 1 < n && board[x + 1][y] > 1)
        dfs(x + 1, y);
    if (y - 1 >= 0 && board[x][y - 1] > 1)
        dfs(x, y - 1);
    if (y + 1 < n && board[x][y + 1] > 1)
        dfs(x, y + 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            if (t == 0)board[i][j] = 2;
            else board[i][j] = t;
        }
    }

    for (int i = 0; i < n; i++) {
        dfs(i, 0);         // 第一列
        dfs(i, n - 1);     // 最后一列
        dfs(0, i);         // 第一行
        dfs(n - 1, i);     // 最后一行
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}