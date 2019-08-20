class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int sum = 0;
        int ans = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            if (sum <= 0)    // 之前的 sum 可以丢弃，从 nums[i] 重新加和
                sum = nums[i];
            else  // 只要 sum 大于 0，即使 nums[i] 小于 0 也可以尝试累加，最大值可能在之后取道
                sum += nums[i];
            ans = max(ans, sum);
        }

        return ans;
    }
};