//
// Created by Yiheng Shu on 2019/9/18.
//

#include <iostream>
#include <cstdio>

using namespace std;

int n;
const int maxn = 35;
int scores[maxn];
int dp[maxn][maxn];
int root[maxn][maxn];

void preOrder(int left, int right) {
    if (left > right) return;
    if (left == right) {
        printf("%d ", left);
        return;
    }
    printf("%d ", root[left][right]);
    preOrder(left, root[left][right] - 1);
    preOrder(root[left][right] + 1, right);
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    cin >> n;
    // 输入的是中序遍历的序列
    for (int i = 1; i <= n; i++) {  // 为了方便用数组索引找到二叉树节点，索引从 1 开始
        cin >> scores[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i][i] = scores[i];
        dp[i][i - 1] = 1;    // 用于子树为空的情况
    }

    // 动态规划方程：dp[i][j] < (dp[i][k - 1] * dp[k + 1][j] + dp[k][k])
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = i; k <= j; k++) {
                if (dp[i][j] < (dp[i][k - 1] * dp[k + 1][j] + dp[k][k])) {
                    dp[i][j] = dp[i][k - 1] * dp[k + 1][j] + dp[k][k];
                    root[i][j] = k;
                }
            }
        }
    }
    printf("%d\n", dp[1][n]);
    preOrder(1, n);

    return 0;
}