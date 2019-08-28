//
// Created by Yiheng Shu on 2019/8/27.
//

/*
假设银行有 N 个窗口。窗口前的黄线将等待区分割为两部分，顾客等待的规则：
- 窗口前黄线内可以容纳 M 名顾客。因此当 N 条线都满员时，NM + 1 名及之后的所有顾客都必须在黄线后等待。
- 每名顾客跨越黄线时将选择最短的队伍等待。如果有两条或多条相同长度的队列，顾客将选择号码最小的队列。
- 顾客 i 需要花费 Ti 完成交易过程。
- 最开始的 N 名顾客被假定为在上午八点接受服务。

给定每个顾客的处理时间，你的程序应该能输出每名顾客的业务被完成时的精确时间。

例如，假定银行有 2 个窗口，每个窗口可以有 2 个顾客在黄线内等候。5 个正在等待业务办理的顾客分别需要 1, 2, 6, 4, 3 分钟。
早上 08:00，顾客 1 在窗口 1 接受服务，顾客 2 在窗口 2 接受服务。顾客 3 在窗口 1 前等待，顾客 4 在窗口 2 前等待。顾客 5 在黄线后等待。
在 08:01，顾客 1 完成，顾客 5 进入窗口 1 的黄线。顾客 2 将在 08:02 离开，
 顾客 4 在 08:06 离开，顾客 3 在 08:07 离开，最终顾客 5 在 08:10 离开。

 */

/*
Sample Input:

2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7

Sample Output:

08:07
08:06
08:10
17:00
Sorry

 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, k, q;          // 窗口数，每个窗口前黄线内的人数容量，顾客数量，问询数量
const int maxk = 1010;
int processTime[maxk];   // 每位顾客的业务处理时长
int queries[maxk];
int finishTime[maxk];    // 每位顾客完成业务的时间
bool sorry[maxk];

class Window {
public:
    int popTime;         // 下一位顾客开始接受服务的时间
    int endTime;         // 当前队列全部完成的时间
    queue<int> que;      // 窗口前的队列

    Window() { popTime = endTime = 0; }
};

vector<Window> windows;

void input() {
    cin >> n >> m >> k >> q;
    for (int i = 0; i < k; i++)
        cin >> processTime[i];
    for (int i = 0; i < q; i++)
        cin >> queries[i];
}

void solve() {
    windows = vector<Window>(n);

    int customerIdx = 0;
    // 首先填充黄线内的位置
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (customerIdx < k) {
                windows[j].que.push(processTime[customerIdx]);
                if (windows[j].endTime >= 540) sorry[customerIdx] = true;
                windows[j].endTime += processTime[customerIdx];
                if (!i) windows[j].popTime = windows[j].endTime;
                finishTime[customerIdx++] = windows[j].endTime;
            }
        }
    }

    // 然后处理黄线后的顾客
    while (customerIdx < k) {
        int minPop = windows[0].popTime, windowIdx = 0;
        for (int i = 1; i < n; i++) {
            if (windows[i].popTime < minPop) {
                windowIdx = i;
                minPop = windows[i].popTime;
            }
        }
        // 为该顾客找到窗口后
        windows[windowIdx].que.pop();
        windows[windowIdx].que.push(processTime[customerIdx]);
        windows[windowIdx].popTime += windows[windowIdx].que.front();
        if (windows[windowIdx].endTime >= 540) sorry[customerIdx] = true;
        windows[windowIdx].endTime += processTime[customerIdx];
        finishTime[customerIdx++] = windows[windowIdx].endTime;
    }
}

void output() {
    for (int i = 0; i < q; i++) {
        if (i) printf("\n");
        int customerIdx = queries[i] - 1;
        int curTime = finishTime[customerIdx];
        if (sorry[customerIdx]) printf("Sorry");
        else printf("%02d:%02d", curTime / 60 + 8, curTime % 60);

    }
}

int main() {
    input();
    solve();
    output();
    return 0;
}
