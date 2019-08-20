class Solution {
public:
    vector <vector<int>> permute(vector<int> &nums) {
        vector <vector<int>> res;
        permute(nums, 0, res);
        return res;
    }

    void permute(vector<int> &nums, int start, vector <vector<int>> &res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            // 对于全排列的第 start 位，把 nums 中 start 位置后面的数字依次移到第一位，再移回原位
            swap(nums[start], nums[i]);
            permute(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
};