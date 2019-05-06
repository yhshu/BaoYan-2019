// 第十届蓝桥杯省赛 C++ A 组 D 题

// #include "stdafx.h"

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Path {
public:
    int pos;
    string path;

    Path(int pos) : pos(pos) {
        path = "";
    }

    Path(int pos, const string &path) : pos(pos), path(path) {}
};

const int maxn = 60;
const int inf = 0x3f3f3f3f;
int R, C;
vector<string> mp;
int vis[maxn][maxn];
queue<Path> que;
int level = 1;

void bfs() {
    que.push(Path(0));
    que.push(Path(-1));

    while (!que.empty()) {
        Path cur = que.front();
        que.pop();

        if (cur.pos == -1) {
            if (!que.empty()) {
                level++;
                que.push(Path(-1));
            } else return;
            continue;
        }

        int curx = cur.pos / C;
        int cury = cur.pos % C;
        cout << "x: " << curx << " , y: " << cury << ", path: " << cur.path << '\n';
        vis[curx][cury] = level;
        if (curx == R - 1 && cury == C - 1) {
            cout << cur.path << endl;
            return;
        }

        if (curx + 1 < R && mp[curx + 1][cury] == '0' && level + 1 < vis[curx + 1][cury])
            que.push(Path(cur.pos + C, cur.path + "D"));
        if (cury - 1 >= 0 && mp[curx][cury - 1] == '0' && level + 1 < vis[curx][cury - 1])
            que.push(Path(cur.pos - 1, cur.path + "L"));
        if (cury + 1 < C && mp[curx][cury + 1] == '0' && level + 1 < vis[curx][cury + 1])
            que.push(Path(cur.pos + 1, cur.path + "R"));
        if (curx - 1 >= 0 && mp[curx - 1][cury] == '0' && level + 1 < vis[curx - 1][cury])
            que.push(Path(cur.pos - C, cur.path + "U"));
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < 55; i++) {
        for (int j = 0; j < 55; j++) {
            vis[i][j] = inf;
        }
    }
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
