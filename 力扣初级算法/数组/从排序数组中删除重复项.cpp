// 原地修改数组，返回新数组长度，即 nums 数组的前 len 个元素是新数组即可
// 采用双指针法

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) return 0;
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] != nums[i]) {  // 新的元素
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};