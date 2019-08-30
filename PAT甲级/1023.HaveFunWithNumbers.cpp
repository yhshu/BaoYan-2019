//
// Created by Yiheng Shu on 2019/8/29.
//

/*
Sample Input:

1234567899
Sample Output:

Yes
2469135798
 */

// 高精度乘法

#include <iostream>
#include <vector>

using namespace std;

string ori;  // original number
vector<int> a;
vector<int> b;
int cnt[15];
bool res;

void input() {
    cin >> ori;
}

bool judge() {
    for (int i = 0; i < 10; i++) {
        if (cnt[i] != 0)
            return false;
    }
    return true;
}

void solve() {
    for (int i = 0; i < ori.size(); ++i) {
        cnt[ori[i] - '0']++;
        a.push_back(ori[i] - '0');
    }

    // 从低位开始乘法
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int t = (carry + a[i] * 2);
        carry = t / 10;
        b.push_back(t % 10);
    }
    while (carry) {
        b.push_back(carry % 10);
        carry /= 10;
    }

    for (int i = 0; i < b.size(); i++) {
        cnt[b[i]]--;
    }

    if (judge())cout << "Yes" << endl;
    else cout << "No" << endl;

    for (int i = b.size() - 1; i >= 0; i--) {
        cout << b[i];
    }
}

int main() {
    input();
    solve();
    return 0;
}