//
// Created by Yiheng Shu on 2019/9/4.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int maxn = 310;

int nPeople, nRelation, nQuery;
unordered_map<string, unordered_set<string>> graph;
unordered_map<string, bool> girl;
bool firstline = true;

void nextline() {
    if (firstline) firstline = false;
    else printf("\n");
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> nPeople >> nRelation;
    for (int i = 0; i < nRelation; i++) {
        string node1, node2;  // 不要使用 int，例如 0000 作为 int 无法区分正负
        cin >> node1 >> node2;
        if (node1[0] == '-') girl[node1] = true;
        if (node2[0] == '-') girl[node2] = true;

        graph[node1].insert(node2);
        graph[node2].insert(node1);
    }

    cin >> nQuery;
    vector<pair<int, int>> sol;
    for (int i = 0; i < nQuery; i++) {
        string a, b;
        cin >> a >> b;

        sol.clear();

        // 找与a同性别的c, c与a相邻；找与b同性别的d，d与b和c相邻
        for (auto c = graph[a].begin(); c != graph[a].end(); c++) {
            if (*c == b) continue;  // 给分点
            if (girl[a] == girl[*c]) {
                for (auto d = graph[b].begin(); d != graph[b].end(); d++) {
                    if (*d == a || *c == *d) continue;  // 给分点
                    if (girl[*d] == girl[b] && graph[*d].find(*c) != graph[*d].end()) {
                        sol.push_back(make_pair(abs(stoi(*c)), abs(stoi(*d))));
                    }
                }
            }
        }

        sort(sol.begin(), sol.end(), cmp);

        if (i) printf("\n");
        printf("%d", sol.size());
        if (!sol.empty()) printf("\n");
        for (int j = 0; j != sol.size(); j++) {
            if (j) printf("\n");
            printf("%04d %04d", sol[j].first, sol[j].second);
        }
    }
    return 0;
}
