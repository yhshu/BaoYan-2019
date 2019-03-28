//
// Created by syh on 19-3-17.
//

/*
 * F:Tram
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Tram network in Zagreb consists of a number of intersections and rails connecting some of them. In every intersection there is a switch pointing to the one of the rails going out of the intersection. When the tram enters the intersection it can leave only in the direction the switch is pointing. If the driver wants to go some other way, he/she has to manually change the switch.

When a driver has do drive from intersection A to the intersection B he/she tries to choose the route that will minimize the number of times he/she will have to change the switches manually.

Write a program that will calculate the minimal number of switch changes necessary to travel from intersection A to intersection B.
输入
The first line of the input contains integers N, A and B, separated by a single blank character, 2 <= N <= 100, 1 <= A, B <= N, N is the number of intersections in the network, and intersections are numbered from 1 to N.

Each of the following N lines contain a sequence of integers separated by a single blank character. First number in the i-th line, Ki (0 <= Ki <= N-1), represents the number of rails going out of the i-th intersection. Next Ki numbers represents the intersections directly connected to the i-th intersection.Switch in the i-th intersection is initially pointing in the direction of the first intersection listed.
输出
The first and only line of the output should contain the target minimal number. If there is no route from A to B the line should contain the integer "-1".
样例输入
3 2 1
2 2 3
2 3 1
2 1 2
样例输出
0
 */

/*
 * 本题为有向图最短路问题，所有路径的代价可能是0或1
 */

#include <iostream>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f
const int minSum = 100 + 10;
int dis[minSum][minSum];
int n, a, b;


void init() {
    for (int i = 0; i < minSum; i++) {
        for (int j = 0; j < minSum; j++) {
            if (i == j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
    }
}

void Floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main() {
    init();

    // 输入
    cin >> n >> a >> b;
    int m;
    for (int u = 1; u <= n; u++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            int v;
            cin >> v;
            if (j == 0)
                dis[u][v] = 0;
            else
                dis[u][v] = 1;
        }
    }

    Floyd();
    int res = dis[a][b];
    if (dis[a][b] == INF)
        res = -1;
    cout << res << endl;
    return 0;
}
