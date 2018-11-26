// See also: 435. Non-overlapping Intervals

/*
样例输入：
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
0

样例输出：
5
*/
#include <algorithm>
#include <iostream>
#define MAXN 110
using namespace std;

struct Program {
  int start;
  int end;
  bool operator<(const Program p) const { return this->end < p.end; }
} programs[MAXN];

int main() {
  int n;
  while (cin >> n && n) {
    int ans = 1;
    int last = 0;
    for (int i = 0; i < n; i++)
      cin >> programs[i].start >> programs[i].end;
    sort(programs, programs + n);
    for (int i = 1; i < n; i++) {
      if (programs[i].start >= programs[last].end) {
        last = i - 1;
        ans += 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
