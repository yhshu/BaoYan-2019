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

#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int n, k, p;
int maxSum; // 各因子之和
int maxFactor;
vector<int> ans;
bool solved = false;
map<int, int> powers;

void input() {
    cin >> n >> k >> p;

    // 用于递归剪枝
    maxFactor = 1;
    while (pow(maxFactor, p) <= (double) n) {
        maxFactor++;
    }
}

int calcPower(int num) {
    if (powers.find(num) == powers.end()) {
        powers[num] = pow(num, p);
    }
    return powers[num];
}

/**
 * 搜索
 * @param pos 搜索位置
 * @param powerSum 幂次和
 * @param factorSum 因子和
 * @param sol 解向量
 */
void dfs(int pos, int powerSum, int factorSum, vector<int> sol, int maxF) {
    if (powerSum > n)
        return;
    if (pos == k) {
        if (powerSum == n && factorSum > maxSum) {
            maxSum = factorSum;
            ans.assign(sol.begin(), sol.end());
            solved = true;
        }
        return;
    }
    int remainN;
    int tempMaxFactor;
    for (int i = maxF; i >= 1; i--) {
        sol.push_back(i);

        tempMaxFactor = 1;

        dfs(pos + 1, powerSum + calcPower(i), factorSum + i, sol, maxF);
        sol.pop_back();
    }
}

void output() {
    if (!solved) {
        cout << "Impossible";
        return;
    }

    cout << n << " = ";
    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << " + ";
        cout << ans[i] << "^" << p;
    }
}

int main() {
    input();
    vector<int> sol;
    dfs(0, 0, 0, sol, maxFactor);
    output();
    return 0;
}
