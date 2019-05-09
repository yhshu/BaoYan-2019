#include "stdafx.h"
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXM = 50010; // 流星个数
const int EDGE = 310; // 图的边长

int M;

struct Meteor {
    int x, y, time;
}; // 流星坐标和时间

int dir[5][2] = {0, 0, 0, 1, 0, -1, 1, 0, -1, 0}; // 方向
int g[EDGE][EDGE]; // 图

int BFS() {
    if (g[0][0] == 0)
        return -1; // 开场死
    if (g[0][0] == -1) // 图中的-1均表示不受任何爆炸影响
        return 0;
    Meteor mov = {0, 0, 0}, cur;
    queue<Meteor> q;
    q.push(mov);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 5; i++) {
            mov.x = cur.x + dir[i][0], mov.y = cur.y + dir[i][1];
            mov.time = cur.time + 1; // （如果逃到mov）到达mov的时间
            if (mov.x < 0 || mov.y < 0 || mov.x > EDGE || mov.y > EDGE)
                continue;
            if (g[mov.x][mov.y] == -1)
                return mov.time; // 成功找到安全点
            if (mov.time < g[mov.x][mov.y]) { // 流星撞击mov的时间晚于从cur逃到mov的时间，否则此路不用继续搜索
                g[mov.x][mov.y] = mov.time; // 逃到mov
                q.push(mov);
            }
        }
    }
    return -1;
}

int main() {
    int x, y, time;
    scanf("%d", &M);
    memset(g, -1, sizeof(g));
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &x, &y, &time);
        // 图的预处理，g[dx][dy]存储(dx, dy)遭受毁灭的时间
        for (int j = 0; j < 5; j++) {
            int dx = x + dir[j][0], dy = y + dir[j][1];
            if (dx < 0 || dx > EDGE || dy < 0 || dy > EDGE)
                continue;
            // 包括撞击点在内的五个点同时遭受破坏
            g[dx][dy] = (g[dx][dy] == -1) ? time : min(g[dx][dy], time);
        }
    }
    printf("%d\n", BFS());
    return 0;
}
