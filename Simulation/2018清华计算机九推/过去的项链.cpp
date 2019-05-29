/*
样例1输入:
6
3 2 -1 1 -1 5

样例1输出:
11
3 4
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 200000 + 5;
int n;
int nums[2 * maxn];
int rev[2 * maxn]; // reversed
int L, R;
int ans;  // 最大美观值

void input() {
    cin >> n;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        nums[i] = nums[i + n] = t;
    }
}

int maxSubArray() {
    int res = 0;
    int pos;
    for (int s = 0; s < n; s++) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (cur >= 0) {
                cur += rev[s + i];
            } else cur = rev[s + i];
            res = max(res, cur);
        }
    }
    return res;
}

void printNums() {
    for (int i = 0; i < 2 * n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void solve() {
    int t;
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l < n; l++) {
            printNums();
            reverse(nums + l, nums + l + len);
            cout << "reverse: " << l << " " << l + len - 1 << endl;

            for(int i = 0; i < n; i++) {
                rev[i] = rev[i + n] = nums[(l + i)];
            }

            printNums();
            t = maxSubArray();
            if (t > ans) {
                L = l + 1;
                R = L + len - 1;
                ans = t;
                cout << "maxSubArray: " << t << ", L: " << L << ", R: " << R << endl;
            }
            reverse(nums + l, nums + l + len);
            cout << "reverse: " << l << " " << l + len - 1 << endl;
            printNums();
        }
    }
}

void output() {
    cout << ans << endl;

    cout << L << " " << (R) << endl;
    cout << L << " " << (R % n) << endl;
}

int main() {
    std::cin.tie(0);
    std::cin.sync_with_stdio(false);

    input();
    solve();
    output();
}
