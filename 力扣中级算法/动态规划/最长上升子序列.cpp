// 1.暴力递归
// 2.带记忆的递归 时间复杂度 O(n^2) 空间复杂度 O(n^2)
// 3.动态规划 求最长上升子序列 时间复杂度 O(n^2) 空间复杂度 O(n)
// 4.动态规划+二分搜索 求最长上升子序列的长度 而不能求其本身 时间复杂度 O(nlogn) 空间复杂度 O(n)

// dp[i] 表示的是前i个数组成的子串的最长子上升序列长度
// 注意，dp[i] 不是一个递增数组，并且 dp[i] 初始值为 1

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        const int n = nums.size();
        if (!n) return 0;
        int ans = 1;
        vector<int> dp(n + 1, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};