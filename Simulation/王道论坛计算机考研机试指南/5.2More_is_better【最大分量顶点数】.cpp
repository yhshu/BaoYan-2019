#include <iostream>

#define maxn 100005
using namespace std;
int tree[maxn]; // 并查集
int sum[maxn]; // sum[i]是i所属的连通分量的顶点数量

int findRoot(int x) {
    if (tree[x] == -1)
        return x;
    int t = findRoot(tree[x]);
    tree[x] = t;
    return t;
}

int main() {
    int n;
    while (cin >> n) {
        for (int i = 1; i < maxn; i++) {
            tree[i] = -1;
            sum[i] = 1; // 所得集合的元素个数为1
        }
        while (n--) {
            int a, b;
            cin >> a >> b;
            a = findRoot(a);
            b = findRoot(b);
            if (a != b) {
                tree[a] = b; // a属于b类
                sum[b] += sum[a]; // b类顶点数加上a类顶点数
            }
        }
        int ans = 1;
        for (int i = 1; i < maxn; i++) {
            if (tree[i] == -1 && sum[i] > ans)
                ans = sum[i];
        }
        cout << ans << endl;
    }
    return 0;
}
