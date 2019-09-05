//
// Created by Yiheng Shu on 2019/9/4.
//

#include <iostream>
#include <set>

using namespace std;

const int maxn = 10010;
int nVertex, nEdge, nQuery;

set<pair<int, int> > edges;
bool firstline = true;

void nextline() {
    if (firstline) firstline = false;
    else printf("\n");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> nVertex >> nEdge;
    for (int i = 0; i < nEdge; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        edges.insert(make_pair(node1, node2));
    }

    cin >> nQuery;
    set<int> nodeSet;
    for (int i = 0; i < nQuery; i++) {
        nodeSet.clear();

        int len;
        cin >> len;

        for (int j = 0; j < len; j++) {
            int node;
            cin >> node;
            nodeSet.insert(node);
        }

        bool isCover = true;
        // check if nodeSet is a vertex cover
        for (auto it = edges.begin(); it != edges.end(); it++) {
            if (nodeSet.find((*it).first) == nodeSet.end() && nodeSet.find((*it).second) == nodeSet.end())
                isCover = false;
        }
        nextline();
        if (isCover) printf("Yes");
        else printf("No");
    }
    return 0;
}
