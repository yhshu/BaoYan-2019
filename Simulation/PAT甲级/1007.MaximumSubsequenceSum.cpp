//
// Created by Yiheng Shu on 2019-08-18.
//

/*
Sample Input:

10
-10 1 2 3 4 -5 -23 3 7 -21

Sample Output:

10 1 4
 */

// 最大子序列和
// 可通过线性时间复杂度找到最大子序列和

#include <iostream>
#include <vector>

using namespace std;

const int inf = 0x3f3f3f3f;
int k;
int maxSum = -inf;
int ansBegin, ansEnd;
vector<int> nums;

void input() {
    cin >> k;
    int t;
    for (int i = 0; i < k; i++) {
        cin >> t;
        nums.push_back(t);
    }
}

void solve() {
    int sum = 0;
    int tBegin;
    for (int i = 0; i < nums.size(); i++) {
        if (sum <= 0) {
            sum = 0;
            tBegin = nums[i];
        }
        sum += nums[i];
        if (sum > maxSum) {
            maxSum = sum;
            ansBegin = tBegin;
            ansEnd = nums[i];
        }
    }
}

void output() {
    if (maxSum < 0) {
        cout << "0 " << nums.front() << " " << nums.back();
    } else {
        cout << maxSum << " " << ansBegin << " " << ansEnd;
    }
}

int main() {
    input();
    solve();
    output();
    return 0;
}
