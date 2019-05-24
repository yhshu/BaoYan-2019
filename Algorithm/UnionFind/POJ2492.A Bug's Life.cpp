#include <iostream>

#define MAXN 2010
using namespace std;
int F[2 * MAXN]; // 用作并查集

int find(int x) {
    if (x == F[x])
        return x;
    return F[x] = find(F[x]);
}

void unite(int x, int y) {
    int f1 = find(x);
    int f2 = find(y);
    if (f1 != f2)
        F[f1] = f2;
}

int main() {
    int cases;
    scanf("%d", &cases);
    for (int c = 1; c <= cases; c++) {
        int n, m;
        bool ok = true;
        scanf("%d%d", &n, &m); // n条虫子，m个关系
        // 并查集初始化
        for (int i = 0; i <= 2 * n; i++)
            F[i] = i;

        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y); // x和y应该不同类
            if (find(x) == find(y) || find(x + n) == find(y + n)) { // 如果x和y同类，发现问题
                ok = false;
                break;
            } else {
                unite(x, y + n);
                unite(x + n, y);
            }
        }
        printf("Scenario #%d:\n", c);
        if (!ok)
            printf("Suspicious bugs found!\n\n");
        else printf("No suspicious bugs found!\n\n");
    }
    return 0;
}
