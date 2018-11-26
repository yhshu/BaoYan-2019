#include <iostream>
#include <queue>
#include <vector>
#define MAXN 510

using namespace std;
vector<int> edge[MAXN];
queue<int> que; // 保存入度为0的结点的队列

int main() {
  int inDegree[MAXN]; // 统计每个结点的入度
  int n, m;
  while (cin >> n >> m) { // n个顶点，m条边
    if (!n && !m)
      break;
    for (int i = 0; i < n; i++) { // 初始化所有结点
      inDegree[i] = 0; // 初始化入度信息，所有结点入度均为0
      edge[i].clear(); // 清空邻接链表
    }
    while (m--) {
      int a, b;
      cin >> a >> b;
      inDegree[b]++;        // 累加结点b的入度
      edge[a].push_back(b); // 将b加入a的邻接链表
    }
    while (que.empty() == false) { // 清空队列
      que.pop();
    }
    for (int i = 0; i < n; i++) { // 统计所有结点的入度
      if (inDegree[i] == 0)
        que.push(i);
    }

    int cnt = 0; // 计数器，初始值为0，累加已经确定拓扑序列的结点个数
    while (que.empty() == false) {
      int nowP = que.front();
      que.pop();
      cnt++;
      for (int i = 0; i < edge[nowP].size(); i++) {
        inDegree[edge[nowP][i]]--;
        if (inDegree[edge[nowP][i]] == 0) {
          que.push(edge[nowP][i]);
        }
      }
    }
    if (cnt == n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
