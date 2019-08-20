// 两数异或，求结果中1的数量

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x ^y;
        int ans = 0;
        while (res) {
            if (res & 1)
                ans++;
            res >>= 1;
        }
        return ans;
    }
};