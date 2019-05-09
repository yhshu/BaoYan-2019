#include "stdafx.h"


#include <iostream>
#include <string>
using namespace std;

const int maxn = 510;
bool dp[maxn][maxn]; // dp[i][j] 表示字符串 str[i...j] 是否为回文子串

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    string str;
    cin >> str;

    // 动态规划数组初始化
    for(int i = 0; i < str.size(); i++) {
        dp[i][i] = true;
    }
    
    for(int i = 0; i < str.size() - 1; i++) {
        if(str[i] == str[i + 1]) {
            dp[i][i + 1] = true;
            cout << str.substr(i, 2) << '\n';
        }
    }

    for(int len = 3; len <= str.size(); len++) {
        for(int start = 0; start + len - 1 < str.size(); start++) {
            // cout << "start: " << start << ", len: " << len << "\n";
            int end = start + len - 1;
            if(str[start] == str[end])
                dp[start][end] = dp[start + 1][end - 1];
            if(dp[start][end])
                cout << str.substr(start, len) << '\n';
        }
    }
    return 0;
}
