//
// Created by Yiheng Shu on 2019/9/1.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int maxn = 20010;
int n, m, k;

struct Edge {
    int v1, v2;

    Edge(int v1, int v2) : v1(v1), v2(v2) {}
};

vector<Edge> edges;

int main() {
    cin >> n >> m;

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        edges.push_back(Edge(x, y));
    }

    vector<int> colors;
    set<int> colorSet;
    bool first = true;

    cin >> k;
    for (int i = 0; i < k; i++) {
        colors.clear();
        colorSet.clear();

        // 输入涂色方案
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            colors.push_back(t);
            colorSet.insert(t);
        }

        // 验证涂色方案
        bool check = true;
        for (int j = 0; j < edges.size(); j++) {
            if (check && colors[edges[j].v1] == colors[edges[j].v2]) {
                // 涂色不合理
                if (first) first = false;
                else cout << "\n";
                cout << "No";
                check = false;
            }
        }
        if (check) {
            if (first) first = false;
            else cout << "\n";
            if (colorSet.empty()) cout << "No";
            else cout << colorSet.size() << "-coloring";
        }
    }
    return 0;
}
