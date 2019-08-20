//
// Created by Yiheng Shu on 19-5-10.
//


// 本题是 01 背包裸题
#include <iostream>

using namespace std;

const int maxn = 110; // 最大草药数
const int maxt = 1010; // 最大时间
int t[maxn];
int v[maxn];
int dp[maxt];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T, M; // 总时间和草药数目
    cin >> T >> M;
    for (int i = 0; i < M; i++) {
        cin >> t[i] >> v[i];
    }

    // 01背包
    for (int i = 0; i < M; i++) {
        for (int j = T; j - t[i] >= 0; j--) {
            // cout << i << " " << j << " " << dp[j] << endl;
            dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
        }
    }

    cout << dp[T] << endl;
    return 0;
}
