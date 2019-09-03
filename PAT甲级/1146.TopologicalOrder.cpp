//
// Created by Yiheng Shu on 2019/9/3.
//

#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1010;
vector<int> graph[maxn];
int inDegree[maxn];
int curDegree[maxn];

void init() {
    for (int i = 0; i < maxn; i++) {
        curDegree[i] = inDegree[i];
    }
}

int main() {
    int nNode, nEdge;
    cin >> nNode >> nEdge;
    for (int i = 0; i < nEdge; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);  // 有向边
        inDegree[to]++;
    }

    vector<int> res;
    int k;
    cin >> k;
    for (int pathIdx = 0; pathIdx < k; pathIdx++) {
        init();
        for (int nodeIdx = 0; nodeIdx < nNode; nodeIdx++) {
            int node;
            cin >> node;
            if (curDegree[node] != 0) {
                if (res.empty() || res.back() != pathIdx)
                    res.push_back(pathIdx);
            } else {
                for (int neiIdx = 0; neiIdx < graph[node].size(); neiIdx++) {
                    curDegree[graph[node][neiIdx]]--;
                }
            }
        }
    }

    // 输出：不是拓扑排序的序列编号
    for (int i = 0; i < res.size(); i++) {
        if (i) cout << " ";
        cout << res[i];
    }
    return 0;
}