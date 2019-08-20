// 方法1: 哈希表
// 方法2: 排序

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_map<int, int> map;
        for (int num: nums) {
            if (map[num] >= 1)
                return true;
            map[num]++;
        }
        return false;
    }
};