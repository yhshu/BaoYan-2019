//
// Created by Yiheng Shu on 2019/9/1.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
const int maxn = 10010;
int state[maxn];  // 每位玩家的陈述：数字是玩家编号
// 正数表示声明指定玩家为人类，负数表示声明指定玩家为狼人

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> state[i];
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> lie;
            vector<int> assumption(n + 1, 1);
            assumption[i] = assumption[j] = -1;  // 假设这两位玩家是狼人
            for (int k = 1; k <= n; k++) {
                if (state[k] * assumption[abs(state[k])] < 0) { // k 的声明与当前假设不符
                    lie.push_back(k);  // 根据当前假设，可认为 k 在说谎
                }
            }
            if (lie.size() == 2 && assumption[lie[0]] + assumption[lie[1]] == 0) {
                // 如果有两个说谎者，并且在当前假设中，一个说谎者是狼人，一个说谎者是人类
                cout << i << " " << j; // 找到一组解后直接退出
                return;
            }
        }
    }
    cout << "No Solution";
}

int main() {
    input();
    solve();
    return 0;
}