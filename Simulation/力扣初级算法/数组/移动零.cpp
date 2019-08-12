class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) { // 注意 i 和 pos 是否可能相等
                int t = nums[i];
                nums[i] = 0;
                nums[pos++] = t;
            }
        }
    }
};