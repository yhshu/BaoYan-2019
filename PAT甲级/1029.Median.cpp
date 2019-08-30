//
// Created by Yiheng Shu on 2019/8/30.
//

/*
Sample Input:

4 11 12 13 14
5 9 10 15 16 17

Sample Output:

13
 */

#include <iostream>

using namespace std;

const int maxn = 200010;
const int inf = 0x3f3f3f3f;

int nums[maxn];
int len1, len2, mid, cnt;
int t;

int main() {
    cin >> len1;
    for (int i = 1; i <= len1; i++) {
        cin >> nums[i];
    }
    nums[len1 + 1] = inf;
    cin >> len2;
    mid = (len1 + len2 + 1) / 2;

    int i = 1;
    for (int j = 1; j <= len2; j++) {
        cin >> t;
        while (nums[i] < t) {
            cnt++;
            if (cnt == mid) cout << nums[i];
            i++;
        }
        cnt++;
        if (cnt == mid) cout << t;
    }
    while (i <= len1) {
        cnt++;
        if (cnt == mid) cout << nums[i++];
    }
    return 0;
}
