// 峰谷法：寻找每一对峰谷，加和得到答案
// 一次遍历：只需判断相邻两天是否有收益

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;

        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};