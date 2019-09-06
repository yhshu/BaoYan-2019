//
// Created by Yiheng Shu on 2019/9/6.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool judge(const vector<int> &nums, int h) {
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > h) cnt++;
        else return cnt >= h;
    }
    return cnt >= h;
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        nums.push_back(t);
    }

    sort(nums.begin(), nums.end(), cmp);
    for (int i = n; i >= 0; i--) {  // 如果从小到大检查，可能会超时
        if (judge(nums, i)) {
            cout << i;
            return 0;
        }
    }
    cout << n;
    return 0;
}