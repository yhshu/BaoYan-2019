//
// Created by Yiheng Shu on 19-3-27.
//

#include <iostream>
#include <queue>
#include <set>
#include <cmath>
#include <cstring>

using namespace std;

const int maxl = 310;
typedef pair<int, int> pii;

class Point {
public:
    int x;
    int y;
    int level;

    Point(int x, int y, int level) : x(x), y(y), level(level) {}
};

int dx[10] = {+1, +2, +2, +1, -1, -2, -2, -1};
int dy[10] = {+2, +1, -1, -2, -2, -1, +1, +2};

int l, sx, sy, ex, ey;
queue<Point> que;
bool vis[maxl][maxl]; // 使用 stl 的 set 将超时
int diff;

void bfs() {
    while (!que.empty()) {
        Point cur = que.front();
        que.pop();

        if (cur.x == ex && cur.y == ey) {
            cout << cur.level << endl;
            return;
        }
        if (cur.level > 3 * diff)
            return;

        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= l || ny >= l) // 超出边界
                continue;
            Point next(nx, ny, cur.level + 1);
            if (vis[nx][ny]) // 已进入过队列
                continue;
            vis[nx][ny] = true;
            que.push(next);
        }
    }
    cout << 0 << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        cin >> l;
        cin >> sx >> sy;
        cin >> ex >> ey;
        if (sx == ex && sy == ey) {
            cout << 0 << endl;
            continue;
        }

        diff = abs(sx - ex) + abs(sy - ey);

        while (!que.empty())
            que.pop();
        memset(vis, false, sizeof(vis));

        Point p(sx, sy, 0);
        vis[sx][sy] = true;
        que.push(p);
        bfs();
    }
}
