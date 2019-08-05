/*
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
 */

class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size())  // 长度不符
            return false;

        bool *dp = new bool[s2.size() + 1]; // 申请动态数组，注意大小
        // 一维数组：dp[j] 表示 s1[0..(i - 1)] s2[0..(j - 1)] s3[0...(i + j - 1)] 是否满足要求
        // dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1] ||
        //            dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]

        for (int i = 0; i <= s1.size(); i++) {
            for (int j = 0; j <= s2.size(); j++) {
                if (i == 0 && j == 0)
                    dp[j] = true;
                else if (i == 0)
                    dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
                else if (j == 0)
                    dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
                else
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                            (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[s2.size()];
    }
};