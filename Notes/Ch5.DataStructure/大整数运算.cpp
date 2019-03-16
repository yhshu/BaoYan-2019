// 2018清华软院九推机试1 大整数乘法
// 2018清华软院九推机试2 大整数排列

#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxlen = 1000;

class BigInteger {
public:
    int d[maxlen]; // 存储大数，数组低位存储大数低位
    int len; // 记录长度

    void clear() {
        memset(d, 0, sizeof(d));
        len = 0;
    }

    BigInteger() {
        clear();
    }

    BigInteger(string str) {
        clear();
        for (int i = str.size() - 1; i >= 0; i--) {
            d[len++] = str[i] - '0';
        }
    }

    string toString() {
        stringstream ss;
        string str;
        for (int i = len - 1; i >= 0; i--) {
            ss << d[i];
        }
        ss >> str;
        return str;
    }

};

BigInteger next_permutation(BigInteger bign) {
    string str = bign.toString();
    if (str.empty() || str.size() == 1) return bign;
    next_permutation(str.begin(), str.end());
    return BigInteger(str);
}

/**
 * 大整数加法
 * 大整数乘法
 * @param a 大整数
 * @param b 大整数
 * @return 大整数 a + b
 */
BigInteger add(BigInteger a, BigInteger b) {
    BigInteger res;
    int carry = 0;
    for (res.len = 0; res.len < max(a.len, b.len); res.len++) {
        int sum = a.d[res.len] + b.d[res.len] + carry;
        res.d[res.len] = sum % 10;
        carry = sum / 10;
    }
    if (carry)
        res.d[res.len++] = carry;
    return res;
}

/**
 * 大整数乘以int
 * @param a 大整数
 * @param b 整数
 * @return 大整数 a * b
 */
BigInteger multiply(BigInteger a, int b) {
    BigInteger res;
    int carry = 0;
    for (res.len = 0; res.len < a.len; ++res.len) {
        int product = a.d[res.len] * b + carry;
        res.d[res.len] = product % 10;
        carry = product / 10;
    }
    if (carry)
        res.d[res.len++] = carry;
    return res;
}

/**
 * 大整数乘法
 * @param a 大整数
 * @param b 大整数
 * @return 大整数 a * b
 */
BigInteger multiply(BigInteger a, BigInteger b) {
    BigInteger res("0");
    for (int j = 0; j < b.len; j++) {
        BigInteger mul = multiply(a, b.d[j]);
        for (int k = 0; k < j; k++) {
            mul = multiply(mul, 10);
        }
        res = add(res, mul);
    }
    return res;
}

int main() {
    string a, b;
    string res;
    while (cin >> a >> b) {
        BigInteger biga(a);
        BigInteger bigb(b);
        res = add(biga, bigb).toString();
        cout << "sum: " << res << endl;
        res = multiply(biga, bigb).toString();
        cout << "product: " << res << endl;
        BigInteger bigc = next_permutation(biga);
        cout << "next_permutation: " << bigc.toString() << endl;
    }
    return 0;
}
