#include <cmath>
#include <iostream>

using namespace std;

bool judge(int x) { // 判断 x 是否为素数
    if (x <= 1)
        return false;
    int bound = (int) sqrt(x) + 1;
    // 计算枚举上界，为防止 double 值带来的精度损失，采用根号值取整后再加1
    for (int i = 2; i < bound; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    int x;
    while (cin >> x)
        cout << (judge(x) ? "yes" : "no") << endl;
    return 0;
}
