// 埃式筛法

class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<int> prime(n + 5, 1);

        for (int i = 2; i < sqrt(n + 0.5); i++) {
            if (!prime[i]) continue;
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 0;  // 不要写成 prime[i]
            }
        }

        for (int i = 2; i < n; i++) {
            // cout << i << " " << prime[i] << endl;
            if (prime[i]) {
                ans++;
            }
        }
        return ans;
    }
};