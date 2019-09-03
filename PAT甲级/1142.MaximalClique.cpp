//
// Created by Yiheng Shu on 2019/9/3.
//

#include<iostream>
#include<vector>
#include<set>

using namespace std;

bool firstline = true;
int nv, ne, nquery;
const int maxnv = 210;
set<int> graph[maxnv];

void nextline() {
    if (firstline) firstline = false;
    else cout << endl;
}

int main() {
    cin >> nv >> ne;
    for (int i = 0; i < ne; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].insert(to);
        graph[to].insert(from);
    }

    cin >> nquery;
    vector<int> nodeList;
    set<int> nodeSet;
    for (int queryIdx = 1; queryIdx <= nquery; queryIdx++) {
        int nNode;
        cin >> nNode;
        nodeList.clear();
        nodeSet.clear();
        for (int nodeIdx = 0; nodeIdx < nNode; nodeIdx++) {
            int node;
            cin >> node;
            nodeList.push_back(node);
            nodeSet.insert(node);
        }

        int cliqueState = 2; // 最大团 2，非最大团的一般团 1，不是团 0
        // 首先判断是否是团，即点集中顶点是否两两相邻
        for (int nodeIdx = 0; nodeIdx < nodeList.size(); nodeIdx++) {
            for (int nodeIdx1 = nodeIdx + 1; nodeIdx1 < nodeList.size(); nodeIdx1++) {
                int node1 = nodeList[nodeIdx];
                int node2 = nodeList[nodeIdx1];
                if (graph[node1].find(node2) == graph[node1].end()) {
                    cliqueState = 0;
                }
            }
            if (!cliqueState) {
                break;
            }
        }

        if (!cliqueState) {
            nextline();
            cout << "Not a Clique";
            continue;
        }

        // 然后判断是否是最大团，即检查剩余顶点中是否有与当前点集都相邻的点
        for (int node = 1; node <= nv; node++) {
            if (nodeSet.find(node) != nodeSet.end()) continue;
            bool allConnected = true;
            for (set<int>::iterator it = nodeSet.begin(); it != nodeSet.end(); it++) {
                if (graph[*it].find(node) == graph[*it].end()) {
                    allConnected = false;
                    break;
                }
            }
            if (allConnected) {
                cliqueState = 1;
                break;
            }
        }

        // 输出判定结果
        nextline();
        if (cliqueState == 0) cout << "Not a Clique";
        else if (cliqueState == 1) cout << "Not Maximal";
        else if (cliqueState == 2) cout << "Yes";
    }
    return 0;
}