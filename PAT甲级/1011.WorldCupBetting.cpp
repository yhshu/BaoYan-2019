//
// Created by Yiheng Shu on 2019/8/27.
//

/*
Sample Input:

1.1 2.5 1.7
1.2 3.1 1.6
4.1 1.2 1.1

Sample Output:

T T W 39.31
 */
#include <iostream>

using namespace std;

double ans = 1;

void input() {
    double w, t, l; // win, tie, loss
    for (int i = 0; i < 3; i++) {
        cin >> w >> t >> l;
        double maxBet = max(w, max(t, l));
        ans *= maxBet;
        if (i) cout << " ";
        if (w == maxBet) { cout << "W"; }
        else if (t == maxBet) { cout << "T"; }
        else if (l == maxBet) { cout << "L"; }
    }
}

void solve() {
    ans = (ans * 0.65 - 1) * 2;
}

void output() {
    printf(" %.2f", ans);
}

int main() {
    input();
    solve();
    output();
    return 0;
}