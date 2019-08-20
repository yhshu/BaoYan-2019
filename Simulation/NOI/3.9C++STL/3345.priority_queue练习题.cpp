//
// Created by Yiheng Shu on 19-3-28.
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

下面10*num行，每行一个正整数n（primeNum < 10000000).

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

const int maxn = 10000010;

int getPrimeNum(int n) {
    int n_old = n;
    int res = 0;
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0 && n_old != i) {
            res++;
//            cout << i << " ";
            while (n % i == 0)
                n = n / i;
        }
    }
//    cout << endl;
    return res;
}

class Node {
public:
    int num;
    int primeNum;

    bool operator<(const Node &node) const {
        if (primeNum < node.primeNum) return true;
        else if (primeNum == node.primeNum) {
            return num < node.num;
        } else
            return false;
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N, t;
    Node node;
    deque<Node> que; // 双端队列
    cin >> N;
    while (N--) {
        for (int i = 0; i < 10; ++i) {
            cin >> t;
            node.num = t;
            node.primeNum = getPrimeNum(t);
            que.push_back(node);
        }
        sort(que.begin(), que.end());
        cout << que.back().num << " " << que.front().num << "\n";
        que.pop_back();
        que.pop_front();
    }
    return 0;
}
