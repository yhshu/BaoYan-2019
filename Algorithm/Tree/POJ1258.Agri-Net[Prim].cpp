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

// Prim 算法求最小生成树
// 选择任意顶点开始，不断选择两端分别在最小生成树集合内与集合外的边中，长度最短的边
// 将对应顶点加入到最小生成树集合中，直至所有顶点都加入
// 常使用优先级队列优化


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 105;

class Edge {
public:
    int to;
    int wei;

    Edge(int to, int wei) : to(to), wei(wei) {}

    bool operator<(const Edge &edge) const {
        return wei > edge.wei;
    }
};

int N;                       // 图中的顶点数量
bool mst[maxn];              // 标识是否在最小生成树集合内
vector<Edge> graph[maxn];   // 图的邻接表存储
priority_queue<Edge> pq;
int ans;                     // 最小生成树的权值

void init() {
    ans = 0;
    pq = priority_queue<Edge>();
    for (int i = 0; i < maxn; i++) {
        graph[i].clear();
        mst[i] = false;
    }
}

void input() {
    int wei;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> wei;
            if (wei == 0) continue;
            graph[i].push_back(Edge(j, wei));
        }
    }
}

void Prim() {
    Edge firstEdge(0, 0);
    pq.push(firstEdge);

    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();

        if (mst[cur.to]) continue;
        mst[cur.to] = true;
        ans += cur.wei;

        for (int i = 0; i < graph[cur.to].size(); i++) {
            Edge nei = graph[cur.to][i];
            if (mst[nei.to])continue;
            pq.push(nei);
        }
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
        Prim();
        output();
    }
    return 0;
}
