/**
POJ 1458. Common Subsequence
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 67602		Accepted: 28225
Description

A subsequence of a given sequence is the given sequence with some elements (possible none) left out. Given a sequence X = < x1, x2, ..., xm > another sequence Z = < z1, z2, ..., zk > is a subsequence of X if there exists a strictly increasing sequence < i1, i2, ..., ik > of indices of X such that for all j = 1,2,...,k, xij = zj. For example, Z = < a, b, f, c > is a subsequence of X = < a, b, c, f, b, c > with index sequence < 1, 2, 4, 6 >. Given two sequences X and Y the problem is to find the length of the maximum-length common subsequence of X and Y.
Input

The program input is from the std input. Each data set in the input contains two strings representing the given sequences. The sequences are separated by any number of white spaces. The input data are correct.
Output

For each set of data the program prints on the standard output the length of the maximum-length common subsequence from the beginning of a separate line.
Sample Input

abcfbc         abfcab
programming    contest
abcd           mnp
Sample Output

4
2
0
Source

Southeastern Europe 2003
 */

#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1005;

char s1[maxn], s2[maxn];
int len1, len2;
int dp[maxn][maxn];
// dp[i][j] 表示s1前i位和s2前j位的最长公共子序列的长度

void init() {
    len1 = strlen(s1);
    len2 = strlen(s2);
    for (int i = 0; i < maxn; i++) {
        dp[i][0] = dp[0][i] = 0;
    }
}

void solve() {
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

int main() {
    while (cin >> s1 >> s2) {
        init();
        solve();
        cout << dp[len1][len2] << endl;
    }
    return 0;
}
