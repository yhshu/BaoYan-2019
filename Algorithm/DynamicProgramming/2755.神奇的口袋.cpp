/**
 * 2755:神奇的口袋
查看 提交 统计 提示 提问
总时间限制: 10000ms 内存限制: 65536kB
描述
有一个神奇的口袋，总的容积是40，用这个口袋可以变出一些物品，这些物品的总体积必须是40。John现在有n个想要得到的物品，每个物品的体积分别是a1，a2……an。John可以从这些物品中选择一些，如果选出的物体的总体积是40，那么利用这个神奇的口袋，John就可以得到这些物品。现在的问题是，John有多少种不同的选择物品的方式。
输入
输入的第一行是正整数n (1 <= n <= 20)，表示不同的物品的数目。接下来的n行，每行有一个1到40之间的正整数，分别给出a1，a2……an的值。
输出
输出不同的选择物品的方式的数目。
样例输入
3
20
20
20
样例输出
3
 */

#include <iostream>

using namespace std;

const int maxn = 25;
const int V = 40;    // 指定总容积
int n;
int nums[maxn];
int dp[45][maxn];  // dp[i][j] 表示体积为 i 时前 j 个物品的选择方案数


void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
}

void solve() {
    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;                  // 边界条件

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];   // 不选择当前物品
            if (i - nums[j - 1] >= 0)  // 选择当前物品
                dp[i][j] += dp[i - nums[j - 1]][j - 1];
        }
    }
}

void output() {
    cout << dp[V][n] << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    input();
    solve();
    output();
}