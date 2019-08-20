//
// Created by Yiheng Shu on 2019-08-17.
//

/*
Sample Input 1:

169 5 2

Sample Output 1:

169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2

Sample Input 2:

169 167 3

Sample Output 2:

Impossible
 */


// 本题考察 DFS + 剪枝

// 递归过程中主要的剪枝策略：
// 1. 幂次和是否已经超过 n
// 2. 每一层递归搜索的开始位置根据已填入的数字进行调整
// 3. 估计剩余的尚未填入的数字，最大能否超过已记录的最大因子和

#include <iostream>
#include <cmath>
#include <map>

#define maxn 410

using namespace std;

int n, k, p;
int maxSum; // 各因子之和
int maxFactor;
int ans[maxn];
bool solved = false;
map<int, int> powers;

int calcPower(int num) {
    if (powers.find(num) == powers.end()) {
        powers[num] = pow(num, p);
    }
    return powers[num];
}

void input() {
    cin >> n >> k >> p;

    // 用于递归剪枝
    maxFactor = 1;
    while (calcPower(maxFactor) <= (double) n) {
        maxFactor++;
    }
}


/**
 * 搜索
 * @param pos 搜索位置
 * @param powerSum 幂次和
 * @param factorSum 因子和
 * @param sol 解向量
 */
void dfs(int pos, int powerSum, int factorSum, int *sol, int maxF) {
    if (n - powerSum < 0) return;
    if (pos == k) {
        if (powerSum == n && factorSum > maxSum) {
            maxSum = factorSum;
            for (int i = 0; i < k; i++) ans[i] = sol[i];
            solved = true;
        }
        return;
    }
    int remainN;
    int tempMaxF;
    for (int i = maxF; i >= 1; i--) {
        sol[pos] = i;
        remainN = n - powerSum - calcPower(i);
        if (remainN >= 0 && factorSum + (k - pos) * i > maxSum) {
            tempMaxF = 1;
            while (pow(tempMaxF, p) <= remainN) tempMaxF++;
            tempMaxF = min(tempMaxF - 1, i);
            dfs(pos + 1, powerSum + calcPower(i), factorSum + i, sol, tempMaxF);
        }
        sol[pos] = 0;
    }
}

void output() {
    if (!solved) {
        cout << "Impossible";
        return;
    }

    cout << n << " = ";
    for (int i = 0; i < k; i++) {
        if (i) cout << " + ";
        cout << ans[i] << "^" << p;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    input();
    int *sol = new int[k + 5];
    dfs(0, 0, 0, sol, maxFactor);
    output();
    return 0;
}
