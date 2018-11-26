#include <iostream>
#define MAXN 100005
using namespace std;
int tree[MAXN];
int sum[MAXN];
int findRoot(int x) {
  if (tree[x] == -1)
    return x;
  int t = findRoot(tree[x]);
  tree[x] = t;
  return t;
}
int main() {
  int n;
  while (cin >> n) {

    for (int i = 1; i < MAXN; i++) {
      tree[i] = -1;
      sum[i] = 1; // 所得集合的元素个数为1
    }
    while (n-- != 0) {
      int a, b;
      cin >> a >> b;
      a = findRoot(a);
      b = findRoot(b);
      if (a != b) {
        tree[a] = b;
        sum[b] += sum[a];
      }
    }
    int ans = 1;
    for (int i = 1; i < MAXN; i++) {
      if (tree[i] == -1 && sum[i] > ans)
        ans = sum[i];
    }
    cout << ans << endl;
  }
  return 0;
}
