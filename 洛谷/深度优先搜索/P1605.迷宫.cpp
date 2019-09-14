//
// Created by Yiheng Shu on 2019/9/13.
//

#include <iostream>
#include <cstdio>

using namespace std;

int n, m, t;
int sx, sy, fx, fy;
int ans;

int dx[5] = {-1, 1, 0, 0};
int dy[5] = {0, 0, -1, 1};

int vis[30]; // 未访问 0；障碍 1

void dfs(int x, int y) {
    if (x == fx && y == fy) {
        ans++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (vis[newx * m + newy])continue;
        if (newx <= 0 || newy <= 0 || newx > n || newy > m) continue;
        vis[newx * m + newy] = 2;
        dfs(newx, newy);
        vis[newx * m + newy] = 0;
    }
}

int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;

    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        vis[x * m + y] = 1; // 障碍
    }

    vis[sx * m + sy] = 2;
    dfs(sx, sy);
    printf("%d", ans);
    return 0;
}
