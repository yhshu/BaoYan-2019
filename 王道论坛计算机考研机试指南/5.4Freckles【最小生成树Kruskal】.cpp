/*
样例输入：
3
1.0 1.0
2.0 2.0
2.0 4.0

样例输出：
3.41
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#define MAXN 105
using namespace std;

int tree[MAXN];
int findRoot(int x) {
  if (tree[x] == -1)
    return x;
  int t = findRoot(tree[x]);
  return tree[x] = t;
}

struct Edge {
  int a, b;
  double cost;
  bool operator<(const Edge &e) const { return this->cost < e.cost; }
} edge[5100];

struct Point {
  double x, y;
  double getDistance(Point p) {
    double t =
        (this->x - p.x) * (this->x - p.x) + (this->y - p.y) * (this->y - p.y);
    return sqrt(t);
  }
} point[MAXN];

int main() {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; i++)
      cin >> point[i].x >> point[i].y;
    int size = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) { // 连接两点的线段抽象成边
        edge[size].a = i;
        edge[size].b = j; // 该边的两个顶点编号
        edge[size].cost = point[i].getDistance(point[j]);
        size++;
      }
    }
    sort(edge, edge + size);
    for (int i = 1; i <= n; i++) {
      tree[i] = -1;
    }
    double ans = 0;
    for (int i = 0; i < size; i++) { // Kruskal 算法
      int a = findRoot(edge[i].a);
      int b = findRoot(edge[i].b);
      if (a != b) {
        tree[a] = b;
        ans += edge[i].cost;
      }
    }
    printf("%.2lf\n", ans);
  }
  return 0;
}
