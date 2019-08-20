#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

bool solve(int a, int b, int c, int &s1, int &s2) {
    if (a == 0) {
        // 解一次方程 bx + c = 0
        if (b != 0) {
            s1 = -c / b - 1;
            s2 = -c / b + 1;
            return true;
        }
        return false;
    }

    // 解二次方程
    if (b * b - 4 * a * c < 0)
        return false;
    double t1 = sqrt(b * b - 4 * a * c);
    //  cout << "t1" << t1;
    double t2 = (double) b * (-1) + t1;
    double t3 = (double) b * (-1) - t1;
    //  cout << "t2" << t2;
    s1 = (int) t2 / (2 * a);
    s2 = (int) t3 / (2 * a);
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    int a, b, c, d, e, f;
    vector<long long> nums;
    set<long long> vis;
    while (t--) {
        cin >> a >> b >> c >> d >> e >> f;
        int na = d - a;
        int nb = e - b;
        int nc = f - c;
        int s1 = 0;
        int s2 = 0;
        bool solved = solve(na, nb, nc, s1, s2);
        // cout << s1 << " " << s2 << endl;

        if (!solved) {
            cout << "ghhnb!" << endl;
            continue;
        }

        for (long long i = max(1, s1); i <= s1 + 2; i++) {
            vis.insert(i);
            long long r = na * i * i + nb * i + nc;
            if (r == 0)
                nums.push_back(i);
        }

        for (long long i = max(1, s2); i <= s2 + 2; i++) {
            if (vis.find(i) != vis.end())
                continue;
            long long r = na * i * i + nb * i + nc;
            if (r == 0)
                nums.push_back(i);
        }
        // cout << s1 << " " << s2 << endl;
        if (nums.empty()) {
            cout << "ghhnb!" << endl;
            continue;
        }

        // sort and output
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            cout << nums[i] << " ";
        }
        cout << nums[nums.size() - 1] << endl;  // no space in the len of this line
        nums.clear();
        vis.clear();
    }
    return 0;
}
