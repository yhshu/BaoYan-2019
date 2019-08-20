//
// Created by Yiheng Shu on 2019-08-20.
//

// 完全背包 模板题
// 数据规模较大，可能出现 TLE
// 开启 O2 优化后不会超时

#include <cstdio>

using namespace std;

const int maxm = 10005;
const int maxt = 100005;
int T, M; // 采药时间，采药数目
int t[maxm];
int v[maxm];
int dp[maxt];

void input() {
    scanf("%d%d", &T, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &t[i], &v[i]);
    }
}

void solve() {
    for (int i = 0; i < M; i++) {
        for (int j = t[i]; j <= maxt; j++) {
            int temp = dp[j - t[i]] + v[i];  // 使用 max 函数将降低
            if (dp[j] < temp)
                dp[j] = temp;
        }
    }
}

void output() {
    printf("%d", dp[T]);
}

int main() {
    input();
    solve();
    output();
    return 0;
}