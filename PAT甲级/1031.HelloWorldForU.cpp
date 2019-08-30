//
// Created by Yiheng Shu on 2019/8/30.
//

// 2 * n1 + n2 - 2 = n, n1 = max{k | k <= n2}

#include <iostream>

using namespace std;

string str;
int n;

void input() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    cin >> str;
    n = str.size();
}

void solve() {
    int n1a = 0;
    int n2a;
    for (int n2 = 3; n2 <= n; n2++) {
        int n1 = (n + 2 - n2) / 2;
        if (n1 <= n2 && 2 * n1 + n2 - 2 == n) {
            n1a = max(n1a, n1);
            n2a = n + 2 - 2 * n1a;
        }
    }

    for (int i = 0; i < n1a; i++) {
        if (i != n1a - 1) {  // 不是最后一行
            printf("%c", str[i]);
            for (int j = 0; j < n2a - 2; j++) printf(" ");
            printf("%c\n", str[str.size() - i - 1]);
        } else {             // 最后一行
            for (int j = n1a - 1; j < n1a + n2a - 1; j++)
                printf("%c", str[j]);
        }
    }
}

int main() {
    input();
    solve();
    return 0;
}