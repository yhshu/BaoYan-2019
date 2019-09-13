//
// Created by Yiheng Shu on 2019/9/13.
//

#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

set<int> s;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        s.insert(t);
    }

    printf("%d\n", s.size());
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        printf("%d ", *it);
    }

    return 0;
}
