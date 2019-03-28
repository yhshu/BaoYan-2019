//
// Created by syh on 19-3-28.
//

/*
 * 3345:priority queue练习题
查看 提交 统计 提问
总时间限制: 2500ms 内存限制: 131072kB
描述
我们定义一个正整数a比正整数b优先的含义是：
*a的质因数数目（不包括自身）比b的质因数数目多；
*当两者质因数数目相等时，数值较大者优先级高。


现在给定一个容器，初始元素数目为0，之后每次往里面添加10个元素，每次添加之后，要求输出优先级最高与最低的元素，并把该两元素从容器中删除。

输入
第一行: num (添加元素次数，num <= 30)

下面10*num行，每行一个正整数n（n < 10000000).

输出
每次输入10个整数后，输出容器中优先级最高与最低的元素，两者用空格间隔。

样例输入
1
10 7 66 4 5 30 91 100 8 9
样例输出
66 5
 */

#include <bits/stdc++.h>

using namespace std;

int getPrimeNum(int);

void init();

struct lcmp {
    bool operator()(int a, int b) {
        int pa = getPrimeNum(a);
        int pb = getPrimeNum(b);
        if (pa > pb)
            return true;
        else if (pa == pb) // 数值大优先级高
            return (a > b);
        else
            return false;
    }
};

struct gcmp {
    bool operator()(int a, int b) {
        int pa = getPrimeNum(a);
        int pb = getPrimeNum(b);
        if (pa < pb)
            return true;
        else if (pa == pb)
            return (a < b);
        else
            return false;
    }
};

const int maxn = 10000010;
priority_queue<int, vector<int>, lcmp> lpq;
priority_queue<int, vector<int>, gcmp> gpq;
int cnt[maxn];
bool isPrime[maxn];
int prime[maxn];
int primeNum[maxn];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    init();
    int num, t;
    cin >> num;
    while (num--) {
        for (int i = 0; i < 10; i++) {
            cin >> t;
            lpq.push(t);
            gpq.push(t);
            cnt[t]++;
        }
        while (cnt[gpq.top()] == 0) gpq.pop();
        while (cnt[lpq.top()] == 0) lpq.pop();

        cout << gpq.top() << " " << lpq.top() << "\n";
        cnt[gpq.top()]--;
        cnt[lpq.top()]--;
        gpq.pop();
        lpq.pop();
    }
    return 0;
}

/**
 * 素数筛法
 */
void init() {
    int j = 0;
    for (int i = 2; i < maxn; i++)
        isPrime[i] = true;

    int m = (int) sqrt(maxn + 0.5);
    for (int i = 2; i <= m; i++) {
        if (!isPrime[i])continue;
        prime[j++] = i;
        for (int j = i * i; j < maxn; j += i) {
            isPrime[j] = false;
        }
    }
    for (int i = m + 1; i < maxn; i++) {
        if (isPrime[i])
            prime[j++] = i;
    }
}

/**
 * 计算质因数数目
 * @param num
 * @return num 的质因数数目
 */
int getPrimeNum(int num) {
    if (primeNum[num]) return primeNum[num];
    if (isPrime[num]) return 0;
    int res = 0;
    for (int i = 0; prime[i] && prime[i] <= num; i++) {
        if (num % prime[i] == 0) {
            res++;
            while (num % prime[i] == 0)
                num /= prime[i];
        }
    }
    primeNum[num] = res;
    return res;
}
