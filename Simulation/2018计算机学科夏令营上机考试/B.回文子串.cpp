//
// Created by syh on 19-3-17.
//

/*
 * B:回文子串
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个字符串，寻找并输出字符串中最长回文子串。回文串即从左到右和从右到左读都一样的字符串。
如果字符串中包含多个回文子串，则返回第一个。

输入
第一行是整数n,字符串的个数(primeNum < 20)
输出
接下来n行，每行一个字符串
字符串的长度不超过100
样例输入
3
ab
babadec
scdedcd
样例输出
a
bab
cdedc
 */

/**
 * 本题的多种解法：参考 LeetCode 5. Longest Palindromic Substring
 * 1. 暴力搜索
 * 2. 动态规划
 * 3. 中心扩展
 * 4. Manacher 算法
 */

#include <iostream>
#include <cstring>

using namespace std;

const int minSum = 21;
int min_i = minSum + 1, max_len = 1;
bool dp[minSum][minSum]; // dp[i][j] 表示 str[i...j] 是否是回文子串

void init() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < minSum; i++)
        dp[i][i] = true;
}

string f(string str) {

    for (int i = 1; i < str.size(); i++) {
        if (str[i - 1] == str[i]) {
            dp[i - 1][i] = true;
            min_i = i - 1;
            max_len = 2;
        }
    }

    for (int len = 3; len <= str.size(); len++) { // 不能枚举i和j，第一层循环应是len，注意循环终止条件可以取等
        for (int i = 0; i + len <= str.size(); i++) { // 注意循环终止条件
            int j = i + len - 1;
            if (str[i] == str[j]) {
                dp[i][j] = dp[i + 1][j - 1];
                if (j - i + 1 > max_len && dp[i][j]) {
                    max_len = j - i + 1;
                    min_i = i;
                }
            }
        }
    }
    return str.substr(min_i, max_len);
}

int main() {
    int n;
    cin >> n;
    string str;
    while (n--) {
        init();
        cin >> str;
        min_i = 0;
        max_len = 1;
        string res = f(str);
        cout << res << endl;
    }
    return 0;
}