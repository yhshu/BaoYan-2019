class Solution {
public:
    int rob(vector<int> &nums) {
        int ans = 0;
        int n = nums.size();
        if (!n) return 0;
        vector<int> dp(n + 5, 0);

        dp[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }

        return dp[n];
    }
};