/*
描述
怪盗基德是一个充满传奇色彩的怪盗，专门以珠宝为目标的超级盗窃犯。而他最为突出的地方，就是他每次都能逃脱中村警部的重重围堵，而这也很大程度上是多亏了他随身携带的便于操作的滑翔翼。

有一天，怪盗基德像往常一样偷走了一颗珍贵的钻石，不料却被柯南小朋友识破了伪装，而他的滑翔翼的动力装置也被柯南踢出的足球破坏了。不得已，怪盗基德只能操作受损的滑翔翼逃脱。



假设城市中一共有N幢建筑排成一条线，每幢建筑的高度各不相同。初始时，怪盗基德可以在任何一幢建筑的顶端。他可以选择一个方向逃跑，但是不能中途改变方向（因为中森警部会在后面追击）。
因为滑翔翼动力装置受损，他只能往下滑行（即：只能从较高的建筑滑翔到较低的建筑）。
他希望尽可能多地经过不同建筑的顶部，这样可以减缓下降时的冲击力，减少受伤的可能性。请问，他最多可以经过多少幢不同建筑的顶部（包含初始时的建筑）？



输入
输入数据第一行是一个整数K（K < 100），代表有K组测试数据。
每组测试数据包含两行：第一行是一个整数N(N <
100)，代表有N幢建筑。第二行包含N个不同的整数，每一个对应一幢建筑的高度h（0 < h <
10000），按照建筑的排列顺序给出。 输出
对于每一组测试数据，输出一行，包含一个整数，代表怪盗基德最多可以经过的建筑数量。
样例输入
3
8
300 207 155 299 298 170 158 65
8
65 158 170 298 299 155 207 300
10
2 1 3 4 5 6 7 8 9 10
样例输出
6
6
9
*/


/**
 * 本题求最长上升/下降子序列，使用动态规划
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110;
int dp[maxn];

int lis(vector<int> &nums) {
    int ans = -1;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] <= nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    int k, n, num;
    cin >> k;
    while (k--) { // k 组测试数据
        // 输入与初始化
        fill_n(dp, sizeof(dp), 1); // memset 按字节操作，此处使用 fill_n
        vector<int> nums;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            nums.push_back(num);
        }

        int ans1 = lis(nums);
        reverse(nums.begin(), nums.end());
        fill_n(dp, sizeof(dp), 1);
        int ans2 = lis(nums);

        cout << max(ans1, ans2) << endl;
    }
}