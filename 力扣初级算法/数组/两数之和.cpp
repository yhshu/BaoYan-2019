// 不要根据示例假设所有数都大于 0，题目没有说明这一点

// 两数之和表示只需要两个数，无需使用递归
// 1. 暴力搜索 时间复杂度 O(n^2)
// 2. 排序后使用二分搜索 时间复杂度 O(n logn)
// 3. 哈希表 空间复杂度 O(n) 时间复杂度 O(1)

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        vector<int> sol;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                sol.push_back(map[complement]);
                sol.push_back(i);
                return sol;
            }
            // 否则没有在 map 中找到 complement
            map[nums[i]] = i;
        }
        return sol;
    }
};

