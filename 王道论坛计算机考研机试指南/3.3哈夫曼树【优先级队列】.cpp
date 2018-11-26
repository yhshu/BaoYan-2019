/*
样例输入：
5
1 2 2 5 9
样例输出：
37
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq; // 小顶堆
int main() {
  int n, t;
  while (cin >> n) {
    int ans = 0;
    while (pq.size())
      pq.pop();
    for (int i = 0; i < n; i++) {
      cin >> t;
      pq.push(t);
    }
    while (pq.size() > 1) {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();
      ans += (a + b); // 结果累加
      pq.push(a + b);
    }
    int top = pq.top();
    cout << ans << endl;
  }
  return 0;
}
