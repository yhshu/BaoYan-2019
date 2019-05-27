/*
 * Agri-Net
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 73010		Accepted: 30237
Description

Farmer John has been elected mayor of his town! One of his campaign promises was to bring internet connectivity to all farms in the area. He needs your help, of course.
Farmer John ordered a high speed connection for his farm and is going to share his connectivity with the other farmers. To minimize cost, he wants to lay the minimum amount of optical fiber to connect his farm to all the other farms.
Given a list of how much fiber it takes to connect each pair of farms, you must find the minimum amount of fiber needed to connect them all together. Each farm must connect to some other farm such that a packet can flow from any one farm to any other farm.
The distance between any two farms will not exceed 100,000.
Input

The input includes several cases. For each case, the first line contains the number of farms, N (3 <= N <= 100). The following lines contain the N x N conectivity matrix, where each element shows the distance from on farm to another. Logically, they are N lines of N space-separated integers. Physically, they are limited in length to 80 characters, so some lines continue onto others. Of course, the diagonal will be 0, since the distance from farm i to itself is not interesting for this problem.
Output

For each case, output a single integer length that is the sum of the minimum length of fiber required to connect the entire set of farms.
Sample Input

4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
Sample Output

28
Source

USACO 102

 */

// 使用并查集表示顶点是否在同一连通分量中
// 使用优先级队列维护还未访问的边

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 105;

class Edge {
public:
    int from;
    int to;
    int wei;

    Edge(int from, int to, int wei) : from(from), to(to), wei(wei) {}

    bool operator<(const Edge &edge) const {
        return wei > edge.wei;
    }
};

int N;                       // 图中的顶点数量
int f[maxn];                 // 用于并查集
priority_queue<Edge> pq;
int ans;                     // 最小生成树的权值
int cnt;                     // 已添加的边计数

int find(int x) {
    if (x == f[x])
        return x;
    f[x] = find(f[x]);
    return f[x];
}

void Union(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)
        return;
    f[fx] = fy;
}

void init() {
    cnt = 0;
    ans = 0;
    pq = priority_queue<Edge>();
    for (int i = 0; i < maxn; i++) {
        f[i] = i;
    }
}

void input() {
    int wei;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> wei;
            if (wei == 0) continue;
            pq.push(Edge(i, j, wei));
        }
    }
}

void Kruskal() {
    while (!pq.empty() || cnt < N - 1) {
        Edge cur = pq.top();
        pq.pop();

        if (find(cur.from) == find(cur.to)) continue;
        ans += cur.wei;
        cnt++;
        Union(cur.from, cur.to);
    }
}

void output() {
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while (cin >> N) {
        init();
        input();
        Kruskal();
        output();
    }
    return 0;
}
