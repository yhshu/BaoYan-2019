//
// Created by Yiheng Shu on 19-5-9.
//

/*
 * 1808:公共子序列
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
我们称序列Z = < z1, z2, ..., zk >是序列X = < x1, x2, ..., xm >的子序列当且仅当存在 严格上升 的序列< i1, i2, ..., ik >，使得对j = 1, 2, ... ,k, 有xij = zj。比如Z = < a, b, f, c > 是X = < a, b, c, f, b, c >的子序列。

现在给出两个序列X和Y，你的任务是找到X和Y的最大公共子序列，也就是说要找到一个最长的序列Z，使得Z既是X的子序列也是Y的子序列。
输入
输入包括多组测试数据。每组数据包括一行，给出两个长度不超过200的字符串，表示两个序列。两个字符串之间由若干个空格隔开。
输出
对每组输入数据，输出一行，给出两个序列的最大公共子序列的长度。
样例输入
abcfbc         abfcab
programming    contest
abcd           mnp
样例输出
4
2
0
来源
翻译自Southeastern Europe 2003的试题
 */

#include <iostream>
#include <string>

using namespace std;

const int maxn = 210;
int dp[maxn][maxn]; // dp[i][j] 表示字符串1的前i个字符和字符串2的前j个字符的最长公共子序列的长度

/**
 * 动态规划数组初始化
 */
void init() {
    for (int i = 0; i < maxn; i++) {
        dp[0][i] = dp[i][0] = 0;
    }
}


/**
 * 求公共子序列长度
 * @param str1 字符串1
 * @param str2 字符串2
 * @return str1 和 str2 的公共子序列长度
 */
int lcs(string str1, string str2) {
    init();
    for (int i = 1; i <= str1.size(); ++i) {
        for (int j = 1; j <= str2.size(); ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[str1.size()][str2.size()];
}

int main() {
    string str1, str2;
    while (cin >> str1) {
        cin >> str2;
        cout << lcs(str1, str2) << endl;
    }
    return 0;
}