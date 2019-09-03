//
// Created by Yiheng Shu on 2019/9/3.
//

#include <iostream>
#include <map>

using namespace std;

int maxNum = 1;
map<int, bool> nums;

void input() {
    int nInt;
    cin >> nInt;
    for (int i = 0; i < nInt; i++) {
        int t;
        cin >> t;
        maxNum = max(maxNum, t);
        nums[t] = true;

    }
}

void solve() {
    for (int i = 1; i <= maxNum + 1; i++) {
        if (!nums[i]) {
            cout << i;
            return;
        }
    }
}

int main() {
    input();
    solve();
    return 0;
}