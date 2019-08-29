//
// Created by Yiheng Shu on 2019/8/28.
//

/*
Sample Input 1:

27 2
Sample Output 1:

Yes
1 1 0 1 1
Sample Input 2:

121 5
Sample Output 2:

No
4 4 1
 */

#include <iostream>
#include <vector>

using namespace std;

int n, b;
vector<int> nums;
bool res = true;

void input() {
    cin >> n >> b;
}

void solve() {
    while (n) {
        nums.push_back(n % b);
        n /= b;
    }
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (nums[i] != nums[size - 1 - i])res = false;
    }
}

void output() {
    cout << (res ? "Yes" : "No") << endl;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (i < nums.size() - 1) cout << " ";
        cout << nums[i];
    }
}

int main() {
    input();
    solve();
    output();
    return 0;
}