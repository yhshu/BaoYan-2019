/*
样例输入：
1
3 3 4 20
0 1 1 1
0 0 1 1
0 1 1 1
1 1 1 1
1 0 0 1
0 1 1 1
0 0 0 0
0 1 1 0
0 1 1 0

样例输出：
11
*/

#include <iostream>
#include <queue>
#define MAXN 55
using namespace std;
int maze[MAXN][MAXN][MAXN];
bool mark[MAXN][MAXN][MAXN];

struct N {
  int x, y, z; // 位置坐标
  int t;       // 所需时间
};
queue<N> que;
int go[][3] = {1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1};
int BFS(int a, int b, int c) {
  while (que.empty() == false) {
    N now = que.front();
    que.pop();
    for (int i = 0; i < 6; i++) {
      int nx = now.x + go[i][0];
      int ny = now.y + go[i][1];
      int nz = now.z + go[i][2];
      if (nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c ||
          maze[nx][ny][nz] == 1 || mark[nx][ny][nz] == true)
        continue;
      N tmp;
      tmp.x = nx;
      tmp.y = ny;
      tmp.z = nz;
      tmp.t = now.t + 1;

      que.push(tmp);
      mark[nx][ny][nz] = true;
      if (nx == a - 1 && ny == b - 1 && nz == c - 1)
        return tmp.t;
    }
  }
  return -1;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int a, b, c, t;
    cin >> a >> b >> c >> t;
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        for (int k = 0; k < c; k++) {
          cin >> maze[i][j][k];
          mark[i][j][k] = false;
        }
      }
    }
    while (que.empty() == false)
      que.pop();
    mark[0][0][0] = true;
    N tmp;
    tmp.t = tmp.x = tmp.y = tmp.z = 0;
    que.push(tmp);
    int rec = BFS(a, b, c);
    if (rec <= t)
      cout << rec << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
