//
// Created by syh on 19-3-27.
//

#include <iostream>

using namespace std;

int ans;

/**
 * 放苹果搜索
 * @param start 至少放置的苹果数，去掉重复放法
 * @param m 苹果数
 * @param n 盘子数
 */
void dfs(int start, int m, int n) {
//    cout << "DFS: " << m << " " << n << endl;
    if (n == 0 || m == 0) {
        if (n == 0 && m == 0)
            ans++;
        return;
    }

    // 本盘子可以放 0～m 个苹果
    for (int i = start; i <= m; i++) {
        dfs(i, m - i, n - 1);
    }
}

int main() {
    int T;
    cin >> T;
    int m, n;
    while (T--) {
        ans = 0;
        cin >> m >> n;
        dfs(0, m, n);
        cout << ans << endl;
    }
    return 0;
}