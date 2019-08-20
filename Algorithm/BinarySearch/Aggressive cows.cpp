//
// Created by Yiheng Shu on 2019/5/26.
//

// 百练 2456.

/*
2456:Aggressive cows
查看 提交 统计 提示 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
输入
* Line 1: Two space-separated integers: N and C

* Lines 2..N+1: Line i+1 contains an integer stall location, xi
输出
* Line 1: One integer: the largest minimum distance
 *
样例输入
5 3
1
2
8
4
9

样例输出
3

提示
OUTPUT DETAILS:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.

Huge input data, scanf is recommended.

来源
USACO 2005 February Gold
 */

// 本题思路是二分搜索，找到最大的牛之间的最近距离

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 5;
int N, C;
int nums[maxn];

/**
 * 判定给定的牛间最短距离是否满足要求
 * @param x 最短距离
 * @return 符合要求true，不符合要求false
 */
bool f(int x) {
    int cnt = 1;
    int pre = nums[0]; // 上一个放牛的隔间位置
    for (int i = 1; i < N; i++) {
        if (nums[i] - pre >= x) {
            cnt++;
            pre = nums[i];
            if (cnt >= C)
                return true;
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> N >> C;   // 隔间的数量和牛的数量
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + N);

    int low = 1, high = nums[N - 1] - nums[0];
    int mid, res;
    while (low <= high) {
        mid = low + (high - low) / 2;
        // cout << low << " " << high << " " << mid << endl;
        if (f(mid)) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}
