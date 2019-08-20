//
// Created by Yiheng Shu on 19-5-10.
//

#include <iostream>

using namespace std;

const int maxn = 25;
int dp[maxn];

int main() {
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i < maxn; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << endl;
    return 0;
}
