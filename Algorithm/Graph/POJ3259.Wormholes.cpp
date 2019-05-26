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

struct Edge {
    int e, w;

    Edge(int ee, int ww) : e(ee), w(ww) {}

    Edge() {}
};

vector<Edge> graph[maxn];    // 整个有向图
int updateTimes[maxn];       // 最短路的改进次数
int dis[maxn];               // dis[i] 是源到 i 的目前最短路长度

int Spfa(int v) {
    for (int i = 1; i <= N; ++i)
        dis[i] = inf;

    dis[v] = 0;
    queue<int> que;
    que.push(v);
    memset(updateTimes, 0, sizeof(updateTimes));

    while (!que.empty()) {
        int s = que.front();
        que.pop();

        for (int i = 0; i < graph[s].size(); ++i) {
            int e = graph[s][i].e;
            if (dis[e] > dis[s] + graph[s][i].w) {
                dis[e] = dis[s] + graph[s][i].w;
                que.push(e);   // 没判队列里是否已经有 e，可能会慢一些
                ++updateTimes[e];
                if (updateTimes[e] >= N)
                    return true;
            }
        }
    }
    return false;
}

void init() {
    for (int i = 1; i < maxn; ++i)
        graph[i].clear();
}

int main() {
    cin >> F;
    while (F--) {
        cin >> N >> M >> W;
        init();
        int s, e, t;
        for (int i = 0; i < M; ++i) {
            cin >> s >> e >> t;
            graph[s].push_back(Edge(e, t));
            graph[e].push_back(Edge(s, t));
        }

        for (int i = 0; i < W; ++i) {
            cin >> s >> e >> t;
            graph[s].push_back(Edge(e, -t));
        }

        if (Spfa(1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
