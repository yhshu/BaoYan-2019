//
// Created by 舒意恒 on 2019/3/28.
//

/*
2726:集合问题
        查看 提交 统计 提问
        总时间限制: 5000ms 内存限制: 65536kB
描述
        有一组正整数，总数不超过1000，其中最大值记为M。现要将它们划分成N个集合，使得每个集合的元素之和与M的差的绝对值的和最小。

集合A中当前各元素之和记为SUM(A)，称为A的负荷；SUM(A)与M之差的绝对值称为A的负荷与理想负荷的偏差，简称为A的偏差。把这些整数划分成N个集合的方法是：
 按照从大到小的顺序，依次为每个整数分别选择一个集合；确定一个整数所属集合时，先计算各集合的负荷，将该整数分配给负荷最小的那个集合。

求使得各集合的偏差之和最小的划分方案中，集合的数目N。如果这样的方案不止一种，则输出各方案中，集合数最大的那种方案的集合数N。
输入
        共输入K+1个整数。其中第一个整数是K代表要划分的整数总数，后面依次是K个整数的值。K不超过1000。
输出
        一个整数，代表集合数N。
样例输入
8
2  4  9
12  16
80  28
72
样例输出
3
 */

#include <iostream>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;
const int inf = 0x3f3f3f3f;
int n, a[1010], minSum = inf, ans = 0;
bool flag;
priority_queue<int, vector<int>, greater<int> > pq; // 小根堆

inline int comp(int x, int y) {
    return x > y;
}

main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1, comp); // a 从大到小排序
    for (int i = 1; i <= n; i++) { // 枚举集合数量
        int total = 0;
        for (int j = 1; j <= i; j++) // 堆中每个元素表示每个集合的和
            pq.push(0);
        for (int j = 1; j <= n; j++) { // 确定一个整数所属集合
            // 实际上不需要记录每个数字属于哪个集合，只需计算各集合的和
            int k = pq.top();
            pq.pop();
            pq.push(k + a[j]); // 每次取出堆中最小的数，加上 a[j]
        }
        for (int j = 1; j <= i; j++) {
            total += abs(a[1] - pq.top()); // a[1] 是 a 中最大值
            pq.pop();
        }
        if (total <= minSum) // 如果相等也需要更新
            ans = i, minSum = total;
        else if (!flag)
            flag = true;
        else // if flag == true
            break; // 加速
    }
    cout << ans;
}
