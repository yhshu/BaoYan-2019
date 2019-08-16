//
// Created by Yiheng Shu on 2019-08-16.
//

/*
Sample Input 1:

8 15
1 2 8 7 2 4 11 15
Sample Output 1:

4 11
Sample Input 2:

7 14
1 8 7 2 4 11 15
Sample Output 2:

No Solution
 */

// 参考 力扣 两数之和

// 逻辑十分简单，可能在时间复杂度上有要求
// 哈希表 时间复杂度 O(n)

#include <iostream>
#include <map>

using namespace std;

int n;  // 硬币数量
int m;  // 支付金额

map<int, int> coins;
const int inf = 0x3f3f3f3f;

int main() {
    cin >> n >> m;
    int ans1 = inf, ans2 = inf;

    int t, t1;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (coins[m - t]) {
            t1 = min(m - t, t);
            if (t1 < ans1) {
                ans1 = t1;
                ans2 = max(m - t, t);
            }
        }
        coins[t]++;
    }
    if (ans1 == inf && ans2 == inf)
        cout << "No Solution";
    else
        cout << ans1 << " " << ans2;
    return 0;
}