/*
样例输入：
3 2
1 2 5 6
2 3 4 5
1 3
0 0
样例输出：
9 11
*/

#include <iostream>
#include <vector>
#define MAXN 105
using namespace std;
struct E {
  int next; // 代表直接相邻的结点
  int c;    // 代表该边的权值
};
vector<E> edge[MAXN]; // 邻接链表

bool mark[MAXN];
int dist[MAXN];

int main() {
  int n, m;
  while ((cin >> n >> m) && n && m) {
    for (int i = 1; i <= n; i++)
      edge[i].clear();

    while (m--) {
      int a, b, c;
      cin >> a >> b >> c;
      E e;
      e.c = c;
      e.next = b;
      edge[a].push_back(e);
      e.next = a;
      edge[b].push_back(e);
    }
    for (int i = 1; i <= n; i++) {
      dist[i] = -1;
      mark[i] = false;
    }
    dist[1] = 0;
    mark[1] = true;
    int cur = 1;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < edge[cur].size(); j++) {
        int t = edge[cur][j].next;
        int c = edge[cur][j].c;
        if (mark[t] == true)
          continue;
        if (dist[t] == -1 || dist[t] > dist[cur] + c)
          dist[t] = dist[cur] + c;
      }
      int min = 0x3f3f3f3f;
      for (int j = 1; j <= n; j++) {
        if (mark[j] == true || dist[j] == -1)
          continue;
        if (dist[j] < min) {
          min = dist[j];
          cur = j;
        }
      }
      mark[cur] = true;
    }
    cout << dist[n] << endl;
  }
  return 0;
}
