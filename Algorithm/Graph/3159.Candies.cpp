//
// Created by Yiheng Shu on 2019/5/26.
//

/*
 * Candies
Time Limit: 1500MS		Memory Limit: 131072K
Total Submissions: 40856		Accepted: 11492
Description

During the kindergarten days, flymouse was the monitor of his class. Occasionally the head-teacher brought the kids of flymouse’s class a large bag of candies and had flymouse distribute them. All the kids loved candies very much and often compared the numbers of candies they got with others. A kid A could had the idea that though it might be the case that another kid B was better than him in some aspect and therefore had a reason for deserving more candies than he did, he should never get a certain number of candies fewer than B did no matter how many candies he actually got, otherwise he would feel dissatisfied and go to the head-teacher to complain about flymouse’s biased distribution.

snoopy shared class with flymouse at that time. flymouse always compared the number of his candies with that of snoopy’s. He wanted to make the difference between the numbers as large as possible while keeping every kid satisfied. Now he had just got another bag of candies from the head-teacher, what was the largest difference he could make out of it?

Input

The input contains a single test cases. The test cases starts with a line with two integers N and M not exceeding 30 000 and 150 000 respectively. N is the number of kids in the class and the kids were numbered 1 through N. snoopy and flymouse were always numbered 1 and N. Then follow M lines each holding three integers A, B and c in order, meaning that kid A believed that kid B should never get over c candies more than he did.

Output

Output one line with only the largest difference desired. The difference is guaranteed to be finite.

Sample Input

2 2
1 2 5
2 1 4
Sample Output

5
Hint

32-bit signed integer type is capable of doing all arithmetic.
Source

POJ Monthly--2006.12.31, Sempr
 */

#include <iostream>
#include <queue>

using namespace std;

const int maxn = 30000 + 5;
const int inf = 0x3f3f3f3f;

bool vis[maxn];
int dis[maxn];               // 顶点到源点的距离
int N, M;                    // 顶点数和边数
int from, to, wei;

class Edge {
public:
    int to;   // 有向边的终点
    int wei;  // 权值
};

bool operator<(const Edge &edge1, const Edge &edge2) {
    return edge1.wei > edge2.wei;
}

priority_queue<Edge> pq;
vector<Edge> graph[maxn]; // 整个图的邻接表

void init() {
    dis[1] = 0;
    for (int i = 2; i < maxn; i++) {
        dis[i] = inf;
    }
}

void input() {
    Edge edge;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> from >> edge.to >> edge.wei;
        graph[from].push_back(edge);
    }
    edge.to = 1;
    edge.wei = 0;
    pq.push(edge);
}

void Dijkstra() {
    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();

        if (vis[cur.to])
            continue;
        vis[cur.to] = true;

        for (int i = 0; i < graph[cur.to].size(); i++) {
            Edge nei = graph[cur.to][i];
            if (vis[nei.to])
                continue;
            dis[nei.to] = min(dis[nei.to], dis[cur.to] + nei.wei);
            pq.push(nei);
        }
    }
}

void output() {
    cout << dis[N] << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    init();
    input();
    Dijkstra();
    output();
    return 0;
}