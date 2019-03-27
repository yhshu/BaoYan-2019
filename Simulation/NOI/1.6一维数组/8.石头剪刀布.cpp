//
// Created by syh on 19-3-27.
/*

08:石头剪刀布
        查看 提交 统计 提问
        总时间限制: 1000ms 内存限制: 65536kB
描述
        石头剪刀布是常见的猜拳游戏。石头胜剪刀，剪刀胜布，布胜石头。如果两个人出拳一样，则不分胜负。

一天，小A和小B正好在玩石头剪刀布。已知他们的出拳都是有周期性规律的，比如：“石头-布-石头-剪刀-石头-布-石头-剪刀……”，就是以“石头-布-石头-剪刀”为周期不断循环的。请问，小A和小B比了N轮之后，谁赢的轮数多？

输入
        输入包含三行。
第一行包含三个整数：N，NA，NB，分别表示比了N轮，小A出拳的周期长度，小B出拳的周期长度。0 < N,NA,NB < 100。
第二行包含NA个整数，表示小A出拳的规律。
第三行包含NB个整数，表示小B出拳的规律。
其中，0表示“石头”，2表示“剪刀”，5表示“布”。相邻两个整数之间用单个空格隔开。
输出
        输出一行，如果小A赢的轮数多，输出A；如果小B赢的轮数多，输出B；如果两人打平，输出draw。
样例输入
10 3 4
0 2 5
0 5 0 2
样例输出
        A
提示
        对于测试数据，猜拳过程为：
A：0 2 5 0 2 5 0 2 5 0
B：0 5 0 2 0 5 0 2 0 5
A赢了4轮，B赢了2轮，双方打平4轮，所以A赢的轮数多。
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
vector<int> b;

/**
 * 胜负判断
 * 石头 0 剪刀 2 布 5
 * @param a
 * @param b
 * @return A胜返回1，平局返回0，A败返回-1
 */
int judge(int a, int b) {
    if (a == b) return 0;
    if (a == 0 && b == 2) return 1;
    if (a == 2 && b == 0) return -1;
    if (a == 0 && b == 5) return -1;
    if (a == 5 && b == 0) return 1;
    if (a == 2 && b == 5) return 1;
    if (a == 5 && b == 2) return -1;
}

int main() {
    int n, na, nb;
    int t;
    cin >> n >> na >> nb;
    for (int i = 0; i < na; i++) {
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < nb; i++) {
        cin >> t;
        b.push_back(t);
    }
    int cntA = 0;
    for (int i = 0; i < n; i++) {
        int ai = i % na;
        int bi = i % nb;
        cntA += judge(a[ai], b[bi]);
    }
    if (cntA > 0)
        cout << "A";
    else if (cntA == 0)
        cout << "draw";
    else cout << "B";
    return 0;
}