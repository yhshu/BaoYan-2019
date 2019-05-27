//
// Created by syh on 19-5-26.
//

/*
 * Wormholes
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 71466		Accepted: 26558
Description

While exploring his many farms, Farmer John has discovered a number of amazing wormholes. A wormhole is very peculiar because it is a one-way path that delivers you to its destination at a time that is BEFORE you entered the wormhole! Each of FJ's farms comprises N (1 ≤ N ≤ 500) fields conveniently numbered 1..N, M (1 ≤ M ≤ 2500) paths, and W (1 ≤ W ≤ 200) wormholes.

As FJ is an avid time-traveling fan, he wants to do the following: start at some field, travel through some paths and wormholes, and return to the starting field a time before his initial departure. Perhaps he will be able to meet himself :) .

To help FJ find out whether this is possible or not, he will supply you with complete maps to F (1 ≤ F ≤ 5) of his farms. No paths will take longer than 10,000 seconds to travel and no wormhole can bring FJ back in time by more than 10,000 seconds.

Input

Line 1: A single integer, F. F farm descriptions follow.
Line 1 of each farm: Three space-separated integers respectively: N, M, and W
Lines 2..M+1 of each farm: Three space-separated numbers (S, E, T) that describe, respectively: a bidirectional path between S and E that requires T seconds to traverse. Two fields might be connected by more than one path.
Lines M+2..M+W+1 of each farm: Three space-separated numbers (S, E, T) that describe, respectively: A one way path from S to E that also moves the traveler back T seconds.
Output

Lines 1..F: For each farm, output "YES" if FJ can achieve his goal, otherwise output "NO" (do not include the quotes).

Sample Input

2
3 3 1
1 2 2
1 3 4
2 3 1
3 1 3
3 2 1
1 2 3
2 3 4
3 1 8
Sample Output

NO
YES
Hint

For farm 1, FJ cannot travel back in time.
For farm 2, FJ could travel back in time by the cycle 1->2->3->1, arriving back at his starting location 1 second before he leaves. He could start from anywhere on the cycle to accomplish this.

 Source

USACO 2006 December Gold
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int F, N, M, W;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;

class Edge {
public:
    int to;
    int wei;

    Edge(int to, int wei) : to(to), wei(wei) {}
};

vector<Edge> graph[maxn];    // 图的邻接表表示
int cnt[maxn];               // 最短路的松弛操作次数
int dis[maxn];               // dis[i] 是源点到顶点 i 的目前最短路长度

void init() {
    for (int i = 0; i < maxn; ++i) {
        graph[i].clear();
        cnt[i] = 0;
        dis[i] = inf;
    }
}

void input() {
    int from, to, wei;
    for (int i = 0; i < M; ++i) {
        cin >> from >> to >> wei;
        graph[from].push_back(Edge(to, wei));
        graph[to].push_back(Edge(from, wei));
    }

    for (int i = 0; i < W; ++i) {
        cin >> from >> to >> wei;
        graph[from].push_back(Edge(to, -wei));
    }
}

/**
 * SPFA 算法
 * @param start 起始顶点
 * @return 有负权环返回 true，无负权环返回 false
 */
bool SPFA(int start) {
    dis[start] = 0;
    queue<int> que;
    que.push(start);

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            Edge edge = graph[cur][i];
            if (dis[edge.to] > dis[cur] + edge.wei) {  // 执行松弛操作
                dis[edge.to] = dis[cur] + edge.wei;
                que.push(edge.to);
                cnt[edge.to]++;
                if (cnt[edge.to] >= N)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> F;
    while (F--) {
        cin >> N >> M >> W;
        init();
        input();
        if (SPFA(1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
