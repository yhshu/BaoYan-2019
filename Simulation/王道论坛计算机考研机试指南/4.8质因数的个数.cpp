/*
题目描述 :
求正整数 N(N>1) 的质因数的个数。
相同的质因数需要重复计算。如 120=2*2*2*3*5 ,共有 5 个质因数。
输入:
可能有多组测试数据,每组测试数据的输入是一个正整数 N , (1<N<10^9) 。
输出 :
对于每组数据,输出 N 的质因数的个数。

样例输入:
120
样例输出:
5
提示:
注意: 1 不是 N 的质因数;若 N 为质数, N 是 N 的质因数。
来源:
2007 年清华大学计算机研究生机试真题
 */

#include <iostream>
#include <cmath>

#define maxn 100010
using namespace std;

bool mark[maxn]; // 合数为 true
int prime[maxn];
int primeSize;

void init() // 素数筛法：筛选出2到100000内的所有素数 
{
    primeSize = 0;
    int m = (int) sqrt(maxn + 0.5);
    for (int i = 2; i <= maxn; i++) {
        if (mark[i]) continue;
        prime[primeSize++] = i;
        if (i >= m) continue;
        for (int j = i * i; j <= maxn; j += i) {
            mark[j] = true;
        }
    }
}

int main() {
    init();
    int n;
    while (cin >> n) {
        int ansPrime[30] = {}; // 按顺序保存分解出的质因数
        int ansSize = 0; // 分解出的质因数个数
        int ansNum[30] = {}; // 保存分解出的质因数对应的幂指数
        for (int i = 0; i < primeSize; i++) // 依次测试素数
        {
            if (n % prime[i] == 0) {// 若该素数能整除被分解数
                ansPrime[ansSize] = prime[i];
                while (n % prime[i] == 0) {
                    ansNum[ansSize]++;
                    n /= prime[i];
                }
                ansSize++;
                if (n == 1) // 被分解为1
                    break;
            }
        }
        if (n != 1) { // 测试完从2到100000的所有质因数，仍未分解到1，则剩余的因数是n，它是大于100000的质因数
            ansPrime[ansSize] = n;
            ansNum[ansSize++] = 1;
        }

        int ans = 0;
        for (int i = 0; i < ansSize; i++) {
            ans += ansNum[i];
        }
        cout << ans << endl;
    }
    return 0;
}
