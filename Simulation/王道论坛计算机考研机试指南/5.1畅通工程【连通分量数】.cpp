#include <iostream>

#define MAXN 1010
using namespace std;
int Tree[MAXN];

int findRoot(int x) {
    if (Tree[x] == -1)
        return x;
    int t = findRoot(Tree[x]);
    Tree[x] = t;
    return t;
}

int main() {
    int n, m; // n个顶点，m条边
    while (cin >> n && n) {
        cin >> m;
        int ans = 0;
        for (int i = 1; i <= n; i++)
            Tree[i] = -1;

        while (m-- != 0) { // 读入边信息
            int a, b;
            cin >> a >> b;
            a = findRoot(a);
            b = findRoot(b);
            if (a != b)
                Tree[a] = b;
        }
        for (int i = 1; i <= n; i++) {
            if (Tree[i] == -1)
                ans++;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}
