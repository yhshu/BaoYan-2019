class Solution {
public:
    const int inf = 0x3f3f3f3f;

    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, inf);  // dp[i] 表示的是凑成金额 i 所需的最少硬币数
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == inf ? -1 : dp[amount];
    }
};