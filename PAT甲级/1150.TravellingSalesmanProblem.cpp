//
// Created by Yiheng Shu on 2019/9/2.
//

#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;

const int maxn = 210;

struct Edge {
public:
    int to;
    int dis;

    Edge(int to, int dis) : to(to), dis(dis) {}
};

int nNode, nEdge, nPath;
vector<Edge> graph[maxn]; // 无向图的邻接表表示

int main() {
    cin >> nNode >> nEdge;
    int minPathDisSum = INT_MAX;
    int minPathDisSumIdx = 1;
    for (int i = 0; i < nEdge; i++) {
        int from, to, dis;
        cin >> from >> to >> dis;
        graph[from].push_back(Edge(to, dis));
        graph[to].push_back(Edge(from, dis));
    }

    cin >> nPath;
    int pathLen;
    vector<int> path;
    set<int> vis;
    int pathDisSum = 0;
    int tsState = 0;
    for (int i = 1; i <= nPath; i++) {
        path.clear();
        vis.clear();
        pathDisSum = 0;
        cin >> pathLen;
        for (int j = 0; j < pathLen; j++) {
            int node;
            cin >> node;
            path.push_back(node);
            vis.insert(node);
        }
        bool hasNextNode = false;
        for (int j = 0; j < pathLen - 1; j++) {
            // 对于路径中的每一顶点
            hasNextNode = false;
            for (int k = 0; k < graph[path[j]].size(); k++) {
                Edge &edge = graph[path[j]][k];
                if (edge.to == path[j + 1]) {
                    pathDisSum += edge.dis;
                    hasNextNode = true;
                    break;
                }
            }
            if (!hasNextNode) {
                break;
            }
        }

        // 注意三种情况的判断，容易失分
        if (!hasNextNode || pathLen < nNode + 1 || vis.size() < nNode || path[0] != path[pathLen - 1]) tsState = 0;
        else if (vis.size() == nNode) {
            if (pathLen == nNode + 1) tsState = 2;
            else if (pathLen > nNode + 1) tsState = 1;
            if (pathDisSum < minPathDisSum) {
                minPathDisSum = pathDisSum;
                minPathDisSumIdx = i;
            }
        }
        // 输出当前路径的结果
        cout << "Path " << i << ": " << (hasNextNode ? to_string(pathDisSum) : "NA") << " ";
        if (!tsState) cout << "(Not a TS cycle)" << endl;
        else if (tsState == 1) cout << "(TS cycle)" << endl;
        else if (tsState == 2) cout << "(TS simple cycle)" << endl;
    }

    cout << "Shortest Dist(" << minPathDisSumIdx << ") = " << minPathDisSum;
    return 0;
}
