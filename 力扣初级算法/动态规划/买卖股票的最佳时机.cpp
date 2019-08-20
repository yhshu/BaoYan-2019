// 一次遍历寻找峰谷
// 存储最小价格和最大利润
// 在遍历过程中，当价格小于最小价格时，更新最小价格
// 当价格大于最小价格时，判断利润是否超过最大露润，并更新最大利润

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};