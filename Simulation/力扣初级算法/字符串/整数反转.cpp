// 测试用例中需要包含：
// 1. 负数
// 2. 末尾为 0 的数
// 3. 计算过程中可能导致溢出的数

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            if (res > INT_MAX / 10 || res < INT_MIN / 10)  // 这个判断不应在乘法之后
                return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};