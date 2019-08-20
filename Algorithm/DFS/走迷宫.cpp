//
// Created by Yiheng Shu on 19-4-18.
//

// NOI 2.5 搜索 走迷宫
// 可参考：第十届蓝桥杯省赛 C++ A 组 D 题

// #include "stdafx.h"

#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int maxn = 45;
int R, C;
vector<string> mp;
bool vis[maxn][maxn];
queue<int> que;
int level = 1;

void bfs() {
    que.push(0);
    que.push(-1);

    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        // cout << "cur:" << cur << '\n';

        if (cur == -1) {
            if (!que.empty()) {
                level++;
                que.push(-1);
            } else return;
            continue;
        }

        int curx = cur / C;
        int cury = cur % C;
        // cout << "x: " << curx << " , y: " << cury << '\n';
        vis[curx][cury] = true;
        if (curx == R - 1 && cury == C - 1) {
            cout << level << endl;
            return;
        }

        if (curx + 1 < R && mp[curx + 1][cury] == '.' && !vis[curx + 1][cury])
            que.push(cur + C);
        if (curx - 1 >= 0 && mp[curx - 1][cury] == '.' && !vis[curx - 1][cury])
            que.push(cur - C);
        if (cury + 1 < C && mp[curx][cury + 1] == '.' && !vis[curx][cury + 1])
            que.push(cur + 1);
        if (cury - 1 >= 0 && mp[curx][cury - 1] == '.' && !vis[curx][cury - 1])
            que.push(cur - 1);
    }
}

int main() {
    cin >> R >> C;
    char ch;
    for (int i = 0; i < R; i++) {
        string line;
        for (int j = 0; j < C; j++) {
            cin >> ch;
            line.push_back(ch);
        }
        mp.push_back(line);
    }

    // 使用 BFS 求最短路径
    bfs();
    return 0;
}
