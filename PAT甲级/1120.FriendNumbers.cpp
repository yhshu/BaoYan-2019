//
// Created by Yiheng Shu on 2019/9/6.
//

#include <iostream>
#include <set>

using namespace std;

set<int> res;
bool firstspace = true;

void nextspace() {
    if (firstspace) firstspace = false;
    else printf(" ");
}

int digitSum(int num) {
    int sum = 0;
    while (num) {
        sum += (num) % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        int d = digitSum(t);
        res.insert(d);
    }

    printf("%d", res.size());
    if (!res.empty()) printf("\n");
    for (auto it = res.begin(); it != res.end(); it++) {
        nextspace();
        printf("%d", *it);
    }
    return 0;
}