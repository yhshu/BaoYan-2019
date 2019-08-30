//
// Created by Yiheng Shu on 2019/8/30.
//

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int n, m, s, d;// 顶点数，边数，起点，终点
const int maxn = 500;
const int inf = 0x3f3f3f3f;

class Edge {
public:
    int to;
    int dis;
    int cost;

    Edge(int to, int dis, int cost) : to(to), dis(dis), cost(cost) {}
};

vector<Edge> graph[maxn];
int dist[maxn];
int costs[maxn];
int pre[maxn];

void input() {
    cin >> n >> m >> s >> d;
    int from, to, dis, cost;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> dis >> cost;
        graph[from].push_back(Edge(to, dis, cost));
        graph[to].push_back(Edge(from, dis, cost));
    }
}

void solve() {
    fill(dist, dist + n, inf);
    fill(costs, costs + n, inf);
    fill(pre, pre + n, -1);
    dist[s] = 0;
    costs[s] = 0;

    queue<int> que;
    que.push(s);

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int nei = graph[cur][i].to;
            if (dist[nei] > dist[cur] + graph[cur][i].dis) {
                dist[nei] = dist[cur] + graph[cur][i].dis;
                costs[nei] = costs[cur] + graph[cur][i].cost;
                pre[nei] = cur;
                que.push(nei);
            } else if (dist[nei] == dist[cur] + graph[cur][i].dis
                       && costs[nei] > costs[cur] + graph[cur][i].cost) {
                costs[nei] = costs[cur] + graph[cur][i].cost;
                pre[nei] = cur;
                que.push(nei);
            }
        }
    }
}

void output() {
    stack<int> path;
    int cur = d;
    while (cur != -1) {
        path.push(cur);
        cur = pre[cur];
    }
    bool first = true;
    while (!path.empty()) {
        if (first) first = false;
        else cout << " ";
        cout << path.top();
        path.pop();
    }
    cout << " " << dist[d] << " " << costs[d];
}

int main() {
    input();
    solve();
    output();
    return 0;
}