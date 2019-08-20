// 参考高精度加法的实现
// 需要考虑的情况：进位，向量可能需要扩展最高位

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {

        int carry = 1; // 加 1
        for (int i = digits.size() - 1; i >= 0; i--) {
            int t = digits[i] + carry;
            digits[i] = t % 10;
            carry = t / 10;
        }
        if (carry) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};

