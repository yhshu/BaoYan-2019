//
// Created by Yiheng Shu on 2019/9/11.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 5001;
int price[maxn];   // 第i天股票的价格
int len[maxn];     // 第i天最长下降子序列的长度
int method[maxn];  // 第i天最长下降子序列的方案数

// 求 LDS 的长度和求 LDS 方案数都是动态规划问题

int main() {
    int n, maxLen = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> price[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (price[j] > price[i]) {  // 延长已存在的最长下降子序列
                len[i] = max(len[i], len[j] + 1);
            }
        }
        if (len[i] == 0)
            len[i]++;  // 如果当前的数是目前为止最大的，则其最长下降子序列是其自身
        maxLen = max(maxLen, len[i]);
        for (int j = 1; j < i; j++) {
            if (len[i] == len[j] && price[i] == price[j])
                method[j] = 0;  // 如果与前面的数列相同，则舍去前面的数列，防止重复计数
            else if (len[i] == len[j] + 1 && price[j] > price[i])
                method[i] += method[j];  // 如果可以接上前面的数列，则继承其方案数
        }
        if (!method[i])
            method[i] = 1;
    }

    int sum = 0; // 用于存储最长下降子序列方案的数量
    for (int i = 1; i <= n; i++) {
        if (len[i] == maxLen) sum += method[i];
    }
    printf("%d %d", maxLen, sum);

    return 0;
}
