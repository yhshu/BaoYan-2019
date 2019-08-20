//
// Created by Yiheng Shu on 2019-08-15.
//

/*
Sample Input:

-1000000 9
Sample Output:

-999,991
*/

#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int ans = a + b;
    // ans 每隔 3 位输出一位逗号
    if (ans < 0) {
        cout << "-";
        ans = -ans;
    }

    stringstream ss;
    ss << ans;
    string str;
    ss >> str;

    int size = str.size();
    for (int i = size - 1; i >= 0; i--) {
        cout << str[size - 1 - i];
        if (i % 3 == 0 && i) cout << ",";
    }
    return 0;
}