//
// Created by Yiheng Shu on 2019/8/26.
//

/*
Sample Input:

2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output:

3 2 1.5 1 2.9 0 3.2
*/

#include<iostream>

using namespace std;

const int maxn = 1005;
int k, n;
double a;
double terms[maxn];

void input() {
    for (int line = 0; line < 2; line++) {
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> n >> a;
            terms[n] += a;
        }
    }
}

void solve() {
    int cnt = 0;
    for (int i = 0; i < maxn; i++) {
        if (terms[i] != 0)
            cnt++;
    }
    printf("%d", cnt);

    for (int i = 1000; i >= 0; i--) {
        if (terms[i] != 0)
            printf(" %d %.1f", i, terms[i]);
    }
}

int main() {
    input();
    solve();
    return 0;
}