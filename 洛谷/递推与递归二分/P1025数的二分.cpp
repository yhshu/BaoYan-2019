//
// Created by Yiheng Shu on 2019-08-21.
//

#include <iostream>

using namespace std;

int n, k;
int ans;

void input() {
    cin >> n >> k;
}

void f(int start, int step, int sum) {
    if (step == k) {
        if (sum == n)
            ans++;
        return;
    }
    for (int i = start; i + sum <= n; i++) {
        f(i, step + 1, sum + i);
    }

}

int main() {
    input();
    f(1, 0, 0);
    cout << ans;
}