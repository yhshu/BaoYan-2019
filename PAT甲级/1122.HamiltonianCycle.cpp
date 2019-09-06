//
// Created by Yiheng Shu on 2019/9/6.
//

#include <iostream>
#include <set>

using namespace std;

const int maxn = 210;
int nNode, nEdge, nQuery;
set<int> graph[maxn];
bool firstline = true;

void nextline() {
    if (firstline) firstline = false;
    else printf("\n");
}

bool judge() {
    set<int> path;
    bool isHamiltonianCycle = true;
    int pathLen, pre, cur;
    cin >> pathLen >> pre;
    int first = pre;
    if (pathLen != nNode + 1) isHamiltonianCycle = false;
    path.insert(pre);

    for (int j = 1; j < pathLen; j++) {
        cin >> cur;
        if (graph[pre].find(cur) == graph[pre].end())
            isHamiltonianCycle = false;
        pre = cur;
        path.insert(cur);
    }

    if (first != cur) return false;
    if (path.size() != nNode) return false;
    return isHamiltonianCycle;
}

int main() {
    cin >> nNode >> nEdge;
    for (int i = 0; i < nEdge; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].insert(node2);
        graph[node2].insert(node1);
    }

    cin >> nQuery;

    for (int i = 0; i < nQuery; i++) {
        nextline();
        if (judge()) printf("YES");
        else printf("NO");
    }
    return 0;
}
