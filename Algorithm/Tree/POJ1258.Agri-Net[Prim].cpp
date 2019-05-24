#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int maxn = 110;
const int inf = 0x3f3f3f3f;
int graph[maxn][maxn];
bool mst[maxn];  // Minimum spanning tree

void mstClear() {
    for(int i = 0; i < maxn; i++)
        mst[i] = false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int mstCnt, ans; 
    int n; // the number of cases
    while(cin >> n) {
        ans = 0;
        mstCnt = 0;
        mstClear();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }

        // Prim 算法求最小生成树
        // 选择任意顶点开始，不断选择两端分别在最小生成树集合内与集合外的边中，长度最短的边
        // 将对应顶点加入到最小生成树集合中，直至所有顶点都加入

        mst[0] = true;
        mstCnt++;
        int minLen;
        int minJ;
        while(mstCnt < n) {
            minLen = inf;
            minJ = -1;
            for(int i = 0; i < n; i++) {
                if(!mst[i]) 
                    continue;
                for(int j = 0; j < n; j++) {
                    if(mst[j] || i == j) continue;
                    if(graph[i][j] < minLen) {
                        minLen = graph[i][j];
                        minJ = j;
                    }
                }
            }

            // it's not connected if minJ == -1
            mst[minJ] = true;
            mstCnt++;
            ans += minLen;
        }
        cout << ans << "\n";
    }
    return 0;
}
