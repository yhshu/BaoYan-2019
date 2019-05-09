#include <iostream>

using namespace std;

const int maxn = 110;
char mp[maxn][maxn];
int n, m;
int ans = 0;

void dfs(int i, int j) {
    if (mp[i][j] == '.')
        return;
    mp[i][j] = '.';
    // cout << "i: "<<i << ", j: " << j << endl;
    if (i + 1 < n)
        dfs(i + 1, j);
    if (i - 1 >= 0)
        dfs(i - 1, j);
    if (j + 1 < m)
        dfs(i, j + 1);
    if (j - 1 >= 0)
        dfs(i, j - 1);
    if (i + 1 < n && j + 1 < m)
        dfs(i + 1, j + 1);
    if (i - 1 >= 0 && j - 1 >= 0)
        dfs(i - 1, j - 1);
    if (i + 1 < n && j - 1 >= 0)
        dfs(i + 1, j - 1);
    if (i - 1 >= 0 && j + 1 < m)
        dfs(i - 1, j + 1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 'W')
                ans++;
            dfs(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}
