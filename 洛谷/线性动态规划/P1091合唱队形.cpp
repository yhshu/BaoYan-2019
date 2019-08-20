//
// Created by Yiheng Shu on 2019-08-20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 105;
int n;          // 同学的总数

void input(vector<int> &nums) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    int t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        nums.push_back(t);
    }
}

/**
 * 求最长上升子序列长度
 * @param dp 用于求长度的临时数组
 * @param nums 原数组
 * @param lis lis[i] 存储 nums[0...i] 的最长上升子序列长度
 */
void solve(vector<int> &dp, vector<int> &nums, vector<int> &lis) {
    int len = 1;
    dp[1] = nums[0];
    lis[0] = 1;

    for (int i = 1; i < n; i++) {
        if (dp[len] < nums[i]) {
            dp[++len] = nums[i];
        } else {
            // 找到 dp 数组中第一个大于等于 nums[i] 的数
            long pos =
                    lower_bound(dp.begin() + 1, dp.begin() + len + 1, nums[i]) - dp.begin();
            dp[pos] = nums[i];
        }
        lis[i] = len;  // 记下 lis 长度
    }
}

void solve(vector<int> &nums) {
    vector<int> dp(n + 5);
    vector<int> lis(n + 5);
    vector<int> lds(n + 5);

    solve(dp, nums, lis);
    reverse(nums.begin(), nums.end());
    solve(dp, nums, lds);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, lis[i] + lds[n - i - 1]);
    }
    cout << n - (ans - 1);
}

int main() {
    vector<int> nums;

    input(nums);
    solve(nums);
    return 0;
}