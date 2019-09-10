//
// Created by Yiheng Shu on 2019/9/9.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;
int a, b;

struct Apple {
    int height;
    int power;
};

vector<Apple> apples;

bool cmp(const Apple &a, const Apple &b) {
    return a.power < b.power;
}

int main() {
    cin >> n >> s;
    cin >> a >> b;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int height, power;
        Apple apple;
        cin >> apple.height >> apple.power;
        apples.push_back(apple);
    }
    sort(apples.begin(), apples.end(), cmp);
    for (int i = 0; i < apples.size(); i++) {
        if (apples[i].height <= a + b && s >= 0) {
            s -= apples[i].power;
            if (s >= 0)
                ans++;
            else break;
        }
    }
    cout << ans;
    return 0;
}
