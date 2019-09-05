//
// Created by Yiheng Shu on 2019/9/5.
//

#include <iostream>
#include <vector>

using namespace std;

int nNode, nEdge;
const int maxn = 510;
vector<int> graph[maxn];  // 无向图的邻接表存储
bool vis[maxn];

void dfs(int node) {
    vis[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        if (vis[graph[node][i]]) continue;
        dfs(graph[node][i]);
    }
}

int main() {
    cin >> nNode >> nEdge;

    for (int edgeIdx = 0; edgeIdx < nEdge; edgeIdx++) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int oddCnt = 0;
    for (int i = 1; i <= nNode; i++) {
        if (i > 1) printf(" ");
        printf("%d", graph[i].size());
        if (graph[i].size() % 2 == 0) oddCnt++;
    }

    dfs(1);
    bool connected = true;
    for (int i = 1; i <= nNode; i++) {
        if (vis[i] == false)
            connected = false;
    }

    if (nNode - oddCnt == 0 && connected) printf("\nEulerian");
    else if (nNode - oddCnt == 2 && connected) printf("\nSemi-Eulerian");
    else printf("\nNon-Eulerian");

    return 0;
}