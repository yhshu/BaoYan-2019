//
// Created by Yiheng Shu on 2019-08-21.
//

// 区间动态规划

#include <iostream>

using namespace std;

const int maxn = 300;
const int inf = 0x3f3f3f3f;
int n;
int nums[maxn];
int sum[maxn];  // sum[i] 是 nums 前i个数[1...i] 的和
int minDP[maxn][maxn];
int maxDP[maxn][maxn];

void input() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        nums[i + n] = nums[i];
        sum[i] = nums[i] + sum[i - 1];
    }

    for (int i = n + 1; i <= 2 * n; i++) {
        sum[i] = sum[n] + sum[i - n];
    }
}

int getSum(int i, int j) {
    int res = sum[j] - sum[(i - 1)];
    return res;
}

void solve() {
    for (int len = 2; len <= n; len++) {
        for (int i = 1, j = i + len - 1; i < 2 * n; i++, j = i + len - 1) {
            minDP[i][j] = inf;

            for (int k = i; k < j; k++) {
                minDP[i][j] = min(minDP[i][j], minDP[i][k] + minDP[k + 1][j] + getSum(i, j));
                maxDP[i][j] = max(maxDP[i][j], maxDP[i][k] + maxDP[k + 1][j] + getSum(i, j));
            }
        }
    }
}

void output() {
    int minAns = inf, maxAns = -inf;
    for (int i = 1; i <= n; i++) {
        minAns = min(minAns, minDP[i][i + n - 1]);
        maxAns = max(maxAns, maxDP[i][i + n - 1]);
    }
    cout << minAns << "\n" << maxAns;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
