#include <iostream>
#include <cstdio>

using namespace std;

int n;
const int maxn = 110;
int nums[maxn];
int sum;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    int ave = sum / n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ave == nums[i]) continue;
        nums[i + 1] += (nums[i] - ave);
        ans++;
    }
    printf("%d", ans);
    return 0;
}
