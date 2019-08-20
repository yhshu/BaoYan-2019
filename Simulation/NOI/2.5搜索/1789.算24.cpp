//
// Created by Yiheng Shu on 19-4-24.
//

/*
 * 1789:算24
查看 提交 统计 提问
总时间限制: 3000ms 内存限制: 65536kB
描述
给出4个小于10个正整数，你可以使用加减乘除4种运算以及括号把这4个数连接起来得到一个表达式。现在的问题是，是否存在一种方式使得得到的表达式的结果等于24。

这里加减乘除以及括号的运算结果和运算的优先级跟我们平常的定义一致（这里的除法定义是实数除法）。

比如，对于5，5，5，1，我们知道5 * (5 – 1 / 5) = 24，因此可以得到24。又比如，对于1，1，4，2，我们怎么都不能得到24。
输入
输入数据包括多行，每行给出一组测试数据，包括4个小于10个正整数。最后一组测试数据中包括4个0，表示输入的结束，这组数据不用处理。
输出
对于每一组测试数据，输出一行，如果可以得到24，输出“YES”；否则，输出“NO”。
样例输入
5 5 5 1
1 1 4 2
0 0 0 0
样例输出
YES
NO
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const double EPS = 1e-5; // 浮点数小于 1e-6，可认为该数等于 0

bool isZero(double x) { // 判断浮点数是否为0
    return fabs(x) <= EPS;
}

/**
 * 判断一组数能否算出 24
 * @param num 数组
 * @param n 数组中元素个数
 * @return 能算出24，true；不能算出，false
 */
bool count24(vector<double> nums, int n) {
    if (n == 1)                       // 数组中仅有一个元素
        return isZero(nums[0] - 24);
    else if (n == 2) {
        if (isZero(nums[0] + nums[1] - 24) || isZero(nums[0] - nums[1] - 24) || isZero(nums[1] - nums[0] - 24) ||
            isZero(nums[0] * nums[1] - 24))
            return true;
        return (nums[1] && isZero(nums[0] / nums[1] - 24)) || (nums[0] && isZero(nums[1] / nums[0] - 24));
    }
    vector<double> r(5);
    for (int i = 0; i < n - 1; i++) { // 取 nums 中两数用于四则运算，注意是枚举 nums 中的两个数字而不是相邻两数
        for (int j = i + 1; j < n; j++) {
            int size = 0;
            for (int k = 0; k < n; k++) { // 将 nums 中剩下的 n - 2 个数存放到数组 r 中
                if (k != i && k != j)
                    r[size++] = nums[k];
            }
            r[size] = nums[i] + nums[j];  // r[size] 等于 nums[i] 和 nums[j] 相加
            if (count24(r, size + 1))
                return true;
            r[size] = nums[i] - nums[j];  // r[size] 等于 nums[i] 和 nums[j] 相减
            if (count24(r, size + 1))
                return true;
            r[size] = nums[j] - nums[i];
            if (count24(r, size + 1))
                return true;
            r[size] = nums[i] * nums[j];  // r[size] 等于 nums[i] 和 nums[j] 相乘
            if (count24(r, size + 1))
                return true;
            if (!isZero(nums[j])) {       // r[size] 等于 nums[i] 和 nums[j] 相除
                r[size] = nums[i] / nums[j];
                if (count24(r, size + 1))
                    return true;
            }
            if (!isZero(nums[i])) {
                r[size] = nums[j] / nums[i];
                if (count24(r, size + 1))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    vector<double> nums(5);
    while (true) {
        for (int i = 0; i < 4; i++) // 输入 4 个元素
            cin >> nums[i];

        if (isZero(nums[0]) && isZero(nums[1]) && isZero(nums[2]) && isZero(nums[3]))
            break;

        if (count24(nums, 4))       // 可算出24
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
