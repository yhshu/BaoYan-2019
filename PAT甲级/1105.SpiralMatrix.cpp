//
// Created by Yiheng Shu on 2019/9/22.
//

#include <iostream>
#include <cmath>

using namespace std;

int n;
const int maxn = 10010;
int nums[maxn];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n, cmp);
    int mindelta = 0x3f3f3f3f;


    return 0;
}
