#include <iostream>
#include <queue>

using namespace std;

int n, a, b;
const int maxn = 210;
int jump[maxn];
bool vis[maxn];

int bfs() {
    queue<int> que;
    que.push(a);
    int level = 0;

    while (!que.empty()) {
        int size = que.size();
        while (size--) {
            int cur = que.front();
            que.pop();

            if (vis[cur]) continue;
            vis[cur] = true;

            if (cur == b) return level;
            if (cur + jump[cur] <= n) que.push(cur + jump[cur]);
            if (cur - jump[cur] >= 0) que.push(cur - jump[cur]);
        }
        level++;
        if (level > n) return -1;
    }
    return -1;
}

int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> jump[i];
    }
    cout << bfs();
    return 0;
}