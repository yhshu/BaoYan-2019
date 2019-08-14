class Solution {
public:
    vector <vector<int>> subsets(vector<int> &nums) {
        vector <vector<int>> res;
        vector<int> sub;

        if (nums.empty()) return res;
        backtrack(res, sub, nums, 0);
        return res;
    }

    void backtrack(vector <vector<int>> &res, vector<int> sub, const vector<int> &nums, int start) {
        res.push_back(sub);

        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            backtrack(res, sub, nums, i + 1);
            sub.pop_back();
        }
    }
};