class Solution {
public:
    vector <vector<int>> subsets(vector<int> &nums) {
        vector <vector<int>> res;
        if (nums.empty()) return res;

        vector<int> subset;
        subsets(res, subset, nums, 0);
        return res;
    }

    void subsets(vector <vector<int>> &res, vector<int> subset, const vector<int> &nums, int start) {
        if (start == nums.size()) {
            res.push_back(subset);
            return;
        }

        subsets(res, subset, nums, start + 1); // 不添加该元素
        subset.push_back(nums[start]);
        subsets(res, subset, nums, start + 1); // 添加该元素
    }
};