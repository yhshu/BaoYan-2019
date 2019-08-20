//
// Created by Yiheng Shu on 2019-08-20.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N, K; // 工作时间，任务总数
const int maxn = 10005;

class Task {
public:
    int start;
    int len;

    Task(int s, int e) : start(s), len(e) {}

    bool operator<(const Task &t) const {
        return start > t.start;
    }
};

vector<Task> tasks;
map<int, int> startCnt;
int dp[maxn];  // dp[i] 表示时间 [i...N] 的最大闲暇时间

void input() {
    cin >> N >> K;
    int start, end;
    for (int i = 0; i < K; ++i) {
        cin >> start >> end;
        tasks.push_back(Task(start, end));
        startCnt[start]++;
    }
}

void solve() {
    sort(tasks.begin(), tasks.end());
    for (int t = N; t >= 1; t--) {
        if (startCnt[t] == 0) {
            dp[t] = dp[t + 1] + 1;
        } else {
            for (int j = 0; j < tasks.size(); j++) {
                if (tasks[j].start == t) {
                    dp[t] = max(dp[t + tasks[j].len], dp[t]);
                }
            }
        }
    }
}

void output() {
    cout << dp[1];
}

int main() {
    input();
    solve();
    output();
    return 0;
}
