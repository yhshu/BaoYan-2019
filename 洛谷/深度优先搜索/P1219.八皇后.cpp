//
// Created by Yiheng Shu on 2019/9/13.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
const int maxn = 15;
bool col[maxn];
bool diag[2 * maxn];
bool counterDiag[2 * maxn];
int sol[maxn];
int ans = 0;

void dfs(int row) {
    if (row == n + 1) {
        if (ans++ < 3) {
            for (int i = 1; i <= n; i++)
                printf("%d ", sol[i]);
            printf("\n");
        }
        return;
    }
    for (int i = 1; i <= n; i++) {

        if (col[i]) continue;
        int t1 = i - row + maxn;
        int t2 = i + row;
        if (diag[t1]) continue;
        if (counterDiag[t2]) continue;

        col[i] = true;
        diag[t1] = true;
        counterDiag[t2] = true;

        sol[row] = i;
        dfs(row + 1);

        col[i] = false;
        diag[t1] = false;
        counterDiag[t2] = false;
    }
}

int main() {
    cin >> n;

    dfs(1);

    printf("%d", ans);
    return 0;
}
