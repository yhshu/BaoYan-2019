//
// Created by Yiheng Shu on 2019/8/29.
//

/*
Sample Input 1:
67 3

Sample Output 1:
484
2

Sample Input 2:
69 3

Sample Output 2:
1353
3
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string n;
int k;
vector<int> nums;

void input() {
    cin >> n >> k;

    for (int i = n.size() - 1; i >= 0; i--) {
        nums.push_back(n[i] - '0');
    }
}

vector<int> convert(vector<int> cur) {
    // reverse
    vector<int> reversed(cur);
    reverse(reversed.begin(), reversed.end());

    vector<int> res;
    int carry = 0;
    for (int i = 0; i < cur.size(); i++) {
        int t = cur[i] + reversed[i] + carry;
        res.push_back(t % 10);
        carry = t / 10;
    }
    while (carry) {
        res.push_back(carry % 10);
        carry /= 10;
    }
    return res;
}

bool judgePalindromic(const vector<int> &vec) {
    int size = vec.size();
    for (int i = 0; i < size; i++) {
        if (vec[i] != vec[size - i - 1])
            return false;
    }
    return true;
}

void print(const vector<int> &vec) {
    for (int i = vec.size() - 1; i >= 0; i--) {
        cout << vec[i];
    }
}

void solve() {
    vector<int> cur = nums;
    if (judgePalindromic(cur)) {
        print(cur);
        cout << "\n" << 0;
        return;
    }

    for (int i = 1; i <= k; i++) {
        cur = convert(cur);
        if (judgePalindromic(cur) || i == k) {
            print(cur);
            cout << "\n" << i;
            return;
        }
    }
}

int main() {
    input();
    solve();
    return 0;
}