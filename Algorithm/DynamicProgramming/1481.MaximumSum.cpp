//
// Created by syh on 19-5-6.
//

/*
 * 1481:Maximum sum
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Given a set of n integers: A={a1, a2,..., an}, we define a function d(A) as below:
                     t1     t2
         d(A) = max{ ∑ai + ∑aj | 1 <= s1 <= t1 < s2 <= t2 <= n }
                    i=s1   j=s2

Your task is to calculate d(A).
输入
The input consists of T(<=30) test cases. The number of test cases (T) is given in the first line of the input.
Each test case contains two lines. The first line is an integer n(2<=n<=50000). The second line contains n integers: a1, a2, ..., an. (|ai| <= 10000).There is an empty line after each case.
输出
Print exactly one line for each test case. The line should contain the integer d(A).
样例输入
1

10
1 -1 2 2 3 -3 4 -4 5 -5
样例输出
13
提示
In the sample, we choose {2,2,3,-3,4} and {5}, then we can get the answer.

Huge input, scanf is recommended.
来源
POJ Contest,Author:Mathematica@ZSU
 */


// 题意为给定数组，从中找到两段连续区间，使它们的和最大

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 50010;
const int inf = 0x3f3f3f3f;
int nums[maxn];
int max1[maxn];
int max2[maxn];
int ans;

void init() {
    ans = -inf;
    for (int i = 0; i < maxn; i++) {
        max1[i] = -inf;
        max2[i] = -inf;
    }
}

int main() {

    int cases;
    scanf("%d", &cases); // 测试用例数

    int n; // the size of the array
    int t; // temp
    while (cases--) {
        init();

        scanf("%d", &n);  // 数组中元素数
        for (int i = 0; i < n; i++) {
            scanf("%d", &t);
            nums[i] = t;
        }

        int cur = 0;
        for (int j = 1; j <= n; j++) {
            if (cur >= 0)
                cur += nums[j - 1];
            else
                cur = nums[j - 1];
            max1[j] = max(max1[j - 1], cur);
        }
        cur = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (cur >= 0)
                cur += nums[j];
            else
                cur = nums[j];
            max2[j] = max(max2[j + 1], cur);
        }
        for (int i = 1; i < n; i++) {
            ans = max(ans, max1[i] + max2[i]);
        }
        printf("%d\n", ans);
    }
}
