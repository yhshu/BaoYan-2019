//
// Created by Yiheng Shu on 2019/9/19.
//

#include <iostream>

using namespace std;

const int maxn = 10010;
int n;
int nums[maxn];
double ans;

int nextFlag(int x) {
    if (!x) return 1;
    if (x == 1) return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    double t;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        ans += (t * i * (n - i + 1));
    }
    printf("%.2f", ans);
    return 0;
}