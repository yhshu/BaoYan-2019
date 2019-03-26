/*
样例输入：
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1

样例输出：
13.333
31.500
*/

#include <algorithm>
#include <iostream>

#define MAXN 1010

using namespace std;

struct Goods {
    double j; // 物品总重量
    double f; // 物品总价值
    double s; // 单位价值的重量
    bool operator<(const Goods &g) const { return this->s > g.s; }
} goods[MAXN];

int main() {
    int F, N;
    while (cin >> F >> N) {
        double ans = 0;
        if (F == -1 && N == -1)
            break;
        for (int i = 0; i < N; i++) {
            cin >> goods[i].j >> goods[i].f;
            goods[i].s = goods[i].j / goods[i].f;
        }
        sort(goods, goods + N);
        for (int i = 0; i < N, F > 0; i++) {
            if (F > goods[i].f) {
                ans += goods[i].j;
                F -= goods[i].f;
            } else {
                ans += F * goods[i].s;
                F = 0;
            }
        }
        printf("%.3f\n", ans);
    }

    return 0;
}
