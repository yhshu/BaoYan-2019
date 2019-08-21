//
// Created by Yiheng Shu on 2019-08-21.
//

#include <iostream>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 110;

int len1, len2;
string str1, str2;
int dp[maxn][maxn];
int score[7][7] = {{5,  -1, -2, -1, -3},
                   {-1, 5,  -3, -2, -4},
                   {-2, -3, 5,  -2, -2},
                   {-1, -2, -2, 5,  -1},
                   {-3, -4, -2, -1, 0}};

void input() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> len1 >> str1;
    cin >> len2 >> str2;
}

int f(char ch) {
    if (ch == 'A') return 0;
    if (ch == 'C') return 1;
    if (ch == 'G') return 2;
    if (ch == 'T') return 3;
    if (ch == '-') return 4;
    return 5;
}

void solve() {
    // 注意，所求最小值可能是负数，dp 需要初始化为 -inf
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            dp[i][j] = -inf;
        }
    }

    // 边界情况
    for (int i = 1; i <= len1; i++)
        dp[i][0] = dp[i - 1][0] + score[f(str1[i - 1])][4];
    for (int j = 1; j <= len2; j++)
        dp[0][j] = dp[0][j - 1] + score[4][f(str2[j - 1])];

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
//            cout << "dp[" << i << "][" << j << "]";
            dp[i][j] = max(dp[i][j], dp[i][j - 1] + score[4][f(str2[j - 1])]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + score[f(str1[i - 1])][4]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + score[f(str1[i - 1])][f(str2[j - 1])]);
//            cout << " = " << dp[i][j] << endl;
        }
    }
}

void output() {
    cout << dp[len1][len2];
}

int main() {
    input();
    solve();
    output();
    return 0;
}