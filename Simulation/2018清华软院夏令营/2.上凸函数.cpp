//
// Created by Yiheng Shu on 19-3-18.
//

/*
 *
在一个上凸函数上均匀采样得到 {f(i) | i = 1, 2 ... N}
有M次询问，每次询问输入两个整数a,b, 求{f(i) - a*i - b | i = 1, 2 ... N}的最大值。
输入：第一行，N 和 M,其中 N,M< 5e5
然后N行，按顺序输入f(i)
然后M行，每行两个整数 a,b
 */

/*
 * 运用性质：f[i] - a * i - b 的最大值处，f函数的切线斜率等于a
 * 二分查找f'[i] = diff[i] 中最小的大于等于a的数的坐标，使用离散差分方程
 * f[i] - a * i - b 取最小值的坐标在 [i - 1, i + 1] 的范围内
 * 注意1：i 在 diff 数组两端的情况
 * 注意2：C++ 中 f[i] 的下标从0开始，但题目中f(i)下标从1开始
 */


#include<bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5, inf = 0x3f3f3f3f;
int n, m;
int f[maxn], diff[maxn]; // diff: f的差分，长度为n-1, 由于f是上凸函数，diff是递减函数

int binary_search(int a) {  // 在diff[i]中搜索最小的大于等于a的数的坐标
    int l = 0, r = n - 2, mid;
    if (diff[0] < a) // diff 递减，之后不可能搜索到大于等于a
        return 0;
    else if (diff[n - 2] > a)
        return n - 2;
    while (true) {
        if (l == r)
            return l;
        else if (l + 1 == r && diff[r] < a && diff[l] >= a)
            return r;

        mid = (l + r) / 2;
        if (diff[mid] >= a) // 搜索右区间
            l = mid;
        else if (diff[mid] < a) // 搜索左区间
            r = mid;
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int i = 0, a, b, ans1, ans2, ans3;
    cin >> n >> m; // n是函数点的数量，m是搜索次数
    for (i = 0; i < n; i++) {
        cin >> f[i];
        if (i > 0)
            diff[i - 1] = f[i] - f[i - 1]; // 离散差分近似切线斜率
    }
    // 注意下标范围
    // f[0...(n-1)]
    // diff[0...(n-2)]

    while (m--) {
        cin >> a >> b;
        i = binary_search(a);
        if (i == 0) {
            ans1 = f[0] - a - b;
            ans2 = f[1] - a * 2 - b;
            ans3 = f[2] - a * 3 - b;
        } else if (i == n - 2) {
            ans1 = f[n - 1] - a * (n - 1 + 1) - b;
            ans2 = f[n - 2] - a * (n - 2 + 1) - b;
            ans3 = f[n - 3] - a * (n - 3 + 1) - b;
        } else {
            ans1 = f[i] - a * (i + 1) - b;
            ans2 = f[i - 1] - a * (i - 1 + 1) - b;
            ans3 = f[i + 1] - a * (i + 1 + 1) - b;
        }
        ans1 = max(ans1, max(ans2, ans3));
        printf("%d\n", ans1);
    }
    return 0;
}
