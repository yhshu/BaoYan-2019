//
// Created by 舒意恒 on 2019-08-12.
//

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int t = 0;
        for (int num: nums) {
            t ^= num;
        }
        t ^= 0;
        return t;
    }
};