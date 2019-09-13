//
// Created by Yiheng Shu on 2019-08-20.
//

// 线性动态规划：LIS 长度

// 最优时间复杂度 O(n*log(n))
// 第一小题非常明显，答案显然是最长非递增子序列的长度
// 第二小题实际上等同于求最长递增子序列的长度，题目没有明示

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int nums[maxn];
int dp1[maxn];
int dp2[maxn];
int size;

int len1, len2;

void input() {
    int num;
    size = 0;
    while (cin >> num) {
        nums[size++] = num;
    }
}

void solve() {
    len1 = 1;
    len2 = 1;
    dp1[len1] = nums[0];
    dp2[len2] = nums[0];

    for (int i = 1; i < size; i++) {
        if (dp1[len1] >= nums[i]) {  // 非递增
            dp1[++len1] = nums[i];
        } else {
            // 使用 nums[i] 替代 dp1[1...len1 + 1] 中第一个小于 nums[i] 的数字
            int pos = upper_bound(dp1 + 1, dp1 + len1 + 1, nums[i], greater<int>()) - dp1;
            dp1[pos] = nums[i];
        }

        if (dp2[len2] < nums[i]) {  // 递增
            dp2[++len2] = nums[i];
        } else {
            // 使用 nums[i] 替代 dp2[1...len2 + 1] 中第一个大于等于 nums[i] 的数字
            int pos = lower_bound(dp2 + 1, dp2 + len2 + 1, nums[i]) - dp2;
            dp2[pos] = nums[i];
        }
    }
}

void output() {
    cout << len1 << "\n" << len2;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
