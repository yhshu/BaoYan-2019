// 1. 回溯
// 2. 自顶向下的动态规划
// 3. 自底向上的动态规划
// 4. 贪心 时间复杂度 O(n) 空间复杂度 O(1)
// 贪心策略：
// - 从前到后：计算当前最大剩余步数是否大于 0，直到遍历到终点
// - 从后到前：判断目标位置能否到达，若能到达，将目标位置不断前移，直至起点

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        if (!n) return true;

        int last = nums.size() - 1;
        for (int i = last; i >= 0; i--) {
            if (nums[i] + i >= last) {
                last = i;
            }
        }
        return last == 0;
    }
};