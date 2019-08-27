//
// Created by Yiheng Shu on 2019/8/27.
//

/*
Sample Input:

3 2 3 1
Sample Output:

41

样例说明：从0到2 上升12秒 停5秒
        从2到3 上升6秒 停5秒
        从3到1 下降8秒 停5秒
*/

#include <iostream>

using namespace std;

int n;
int cur = 0;
int ans = 0; // 所需时间

void input() {
    cin >> n;
    int f;
    for (int i = 0; i < n; i++) {
        cin >> f;
        if (f > cur) {          // 上升
            ans = ans + 6 * (f - cur) + 5;
        } else if (cur > f) {   // 下降
            ans = ans + 4 * (cur - f) + 5;
        } else {
            ans += 5;
        }
        cur = f;
    }
}

void output() {
    cout << ans;
}

int main() {
    input();
    output();
    return 0;
}