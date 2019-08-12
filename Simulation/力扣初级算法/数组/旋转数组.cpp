// nums 数组循环右移 k 位
// 1. 暴力法：实现循环右移 1 位的函数，执行 k 次
// 2. 使用额外的数组：时间复杂度 O(1) 空间复杂度 O(n)
// 3. 使用环状替换
// 4. 使用反转

/*
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
1 步: [7,1,2,3,4,5,6]
2 步: [6,7,1,2,3,4,5]
3 步: [5,6,7,1,2,3,4]
*/

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

    void reverse(vector<int> &nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};