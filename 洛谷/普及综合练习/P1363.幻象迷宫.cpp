//
// Created by Yiheng Shu on 2019/9/9.
//

#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
const int maxn = 1510;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int startX, startY;
int board[maxn][maxn];
int vis[maxn][maxn][3];
bool found;

void dfs(int x, int y, int rx, int ry) {
    if (found) return;
    if (vis[x][y][0] && !(vis[x][y][1] == rx && vis[x][y][2] == ry)) {
        found = true;
        return;
    }

    vis[x][y][0] = true;
    vis[x][y][1] = rx;
    vis[x][y][2] = ry;

    for (int i = 0; i < 4; i++) {
        int newX = (x + dx[i] + n) % n;
        int newY = (y + dy[i] + m) % m;
        int newRx = rx + dx[i];
        int newRy = ry + dy[i];

        if (board[newX][newY] == 1)continue;
        if (!vis[newX][newY][0] || vis[newX][newY][1] != newRx ||
            vis[newX][newY][2] != newRy) {
            dfs(newX, newY, newRx, newRy);
        }
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while (cin >> n >> m) {
        found = false;
        memset(board, 0, sizeof(board));
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch;
                cin >> ch;
                if (ch == '#') board[i][j] = 1;
                else if (ch == 'S') startX = i, startY = j;
            }
        }

        dfs(startX, startY, startX, startY);
        if (found) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}