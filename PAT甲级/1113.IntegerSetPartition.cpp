#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    int nDelta, SDelta;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    sort(nums.begin(), nums.end());
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n / 2; i++)
        s1 += nums[i];
    for (int i = n / 2; i < n; i++)
        s2 += nums[i];
    SDelta = s2 - s1;
    if (nums.size() % 2 == 1)
        nDelta = 1;
    else
        nDelta = 0;

    cout << nDelta << " " << SDelta;

    return 0;
}