//
// Created by syh on 19-3-17.
//

/*
 * 4078:实现堆结构
查看 提交 统计 提示 提问
总时间限制: 3000ms 单个测试点时间限制: 1000ms 内存限制: 65536kB
描述
定义一个数组，初始化为空。在数组上执行两种操作：

1、增添1个元素，把1个新的元素放入数组。

2、输出并删除数组中最小的数。

使用堆结构实现上述功能的高效算法。

输入
第一行输入一个整数n，代表操作的次数。
每次操作首先输入一个整数type。
当type=1，增添操作，接着输入一个整数u，代表要插入的元素。
当type=2，输出删除操作，输出并删除数组中最小的元素。
1<=n<=100000。
输出
每次删除操作输出被删除的数字。
样例输入
4
1 5
1 1
1 7
2
样例输出
1
提示
每组测试数据的复杂度为O(nlogn)的算法才能通过本次，否则会返回TLE(超时)
需要使用最小堆结构来实现本题的算法
 */

// 本题使用 STL 可直接 AC.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    int t, n, op, num;
    cin >> n;
    while (n--) {
        cin >> op;
        if (op == 1) { // 插入操作
            cin >> num;
            pq.push(num);
        } else if (op == 2) { // 删除操作
            num = pq.top();
            pq.pop();
            cout << num << endl;
        }
    }
    return 0;
}