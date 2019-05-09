#include "stdafx.h"

#include <iostream>

using namespace std;

const int maxn = 100005;
bool check[maxn];
int tot;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int count[7], sum = 0, value[] = {0, 1, 2, 3, 5, 10, 20};
    for (int i = 1; i <= 6; i++) {
        cin >> count[i];
        sum += value[i] * count[i];
    }
    check[0] = true;  // 价值为 0 是可取的
    for (int i = 1; i <= 6; i++)
        for (int j = sum; j > 0; j--)
            for (int k = 1; k <= count[i]; k++)
                if (j - k * value[i] >= 0 && check[j - k * value[i]] && !check[j]) {
                    check[j] = true;
                    tot++;
                }
    cout << "Total=" << tot << endl;
    return 0;
}
