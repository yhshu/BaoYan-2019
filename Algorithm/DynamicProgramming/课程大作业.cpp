/*
 * 4149:课程大作业
查看 提交 统计 提示 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
小明是北京大学信息科学技术学院三年级本科生。他喜欢参加各式各样的校园社团。这个学期就要结束了，每个课程大作业的截止时间也快到了，可是小明还没有开始做。每一门课程都有一个课程大作业，每个课程大作业都有截止时间。如果提交时间超过截止时间X天，那么他将会被扣掉X分。对于每个大作业，小明要花费一天或者若干天来完成。他不能同时做多个大作业，只有他完成了当前的项目，才可以开始一个新的项目。小明希望你可以帮助他规划出一个最好的办法(完成大作业的顺序)来减少扣分。

输入
输入包含若干测试样例。
输入的第一行是一个正整数T，代表测试样例数目。
对于每组测试样例，第一行为正整数N（1 <= N <= 15）代表课程数目。
接下来N行，每行包含一个字符串S（不多于50个字符）代表课程名称和两个整数D（代表大作业截止时间）和C（完成该大作业需要的时间）。
注意所有的课程在输入中出现的顺序按照字典序排列。
输出
对于每组测试样例，请输出最小的扣分以及相应的课程完成的顺序。
如果最优方案有多个，请输出字典序靠前的方案。
样例输入
2
3
Computer 3 3
English 20 1
Math 3 2
3
Computer 3 3
English 6 3
Math 6 3
样例输出
2
Computer
Math
English
3
Computer
English
Math
提示
第二个测试样例, 课程完成顺序Computer->English->Math 和 Computer->Math->English 都会造成3分罚分, 但是我们选择前者,因为在字典序中靠前.
 */


// 状态压缩动态规划

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int t;
int n;

const int maxn = 20;
const int maxc = 55;
const int inf = 0x3f3f3f3f;

struct Homework {
    string name;
    int d;          // 截止时间
    int c;          // 要花的时间
};
Homework hw[maxn];

struct Node {       // 动态规划的状态结点
    int pre;        // 上一个状态，比当前状态完成的作业数少 1
    int last;       // 当前状态下，最后完成的作业的编号
    int minScore;   // 当前状态的分数
    int finishDay;  // 作业last完成的时间
};
Node dp[(1 << 16) + maxn];

vector<int> GetPath(int status) {  // 从状态 status 出发找出作业完成的顺序
    vector<int> path;
    while (status) {
        path.push_back(dp[status].last);
        status = dp[status].pre;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    cin >> t;
    while (t--) {
        // 输入
        cin >> n;
        char name[maxc];
        int d, c;
        for (int i = 0; i < n; ++i)
            cin >> hw[i].name >> hw[i].d >> hw[i].c;
        dp[0].finishDay = 0;
        dp[0].minScore = 0;
        dp[0].pre = -1;
        int m = (1 << n);                    // m 是所有作业的状态总数

        // 状态压缩 DP
        for (int i = 1; i < m; ++i) {        // i 代表已完成作业的集合
            dp[i].minScore = inf;            // 最少被扣分数，默认 inf
            for (int j = 0; j < n; ++j) {    // 遍历所有作业
                if (i & (1 << j)) {          // i 包含第 j 个作业
                    int pre = i - (1 << j);  // 在求 dp[i] 时，任何 dp[pre] 都已经计算，因为 pre < i
                    int finishDay = dp[pre].finishDay + hw[j].c;
                    int tmpScore = finishDay - hw[j].d;   // 完成该课程后的时间 减 该课程截止时间
                    // tmpScore 表示因为这门课被扣除的分数，如果小于 0 则不扣分
                    if (tmpScore < 0)
                        tmpScore = 0;
                    if (dp[i].minScore > dp[pre].minScore + tmpScore) {
                        dp[i].minScore = dp[pre].minScore + tmpScore;
                        dp[i].pre = pre;
                        dp[i].finishDay = finishDay;
                        dp[i].last = j;
                    }
                    if (dp[i].minScore == dp[pre].minScore + tmpScore) {
                        vector<int> p1 = GetPath(dp[i].pre);
                        vector<int> p2 = GetPath(pre);
                        // 保证 p1 <= p2
                        // 由于输入的课程名称是按字典序排列
                        // 只需要直接比较状态编号的大小就可以在输出中获得字典序最小的结果
                        if (p2 < p1) {
                            dp[i].pre = pre;
                            dp[i].finishDay = finishDay;
                            dp[i].last = j;
                        }
                    }
                }
            }
        }

        // 输出
        cout << dp[m - 1].minScore << endl;
        int status = m - 1;
        vector<int> path = GetPath(status);
        for (int i = 0; i < path.size(); ++i)
            cout << hw[path[i]].name << endl;
    }
    return 0;
}
