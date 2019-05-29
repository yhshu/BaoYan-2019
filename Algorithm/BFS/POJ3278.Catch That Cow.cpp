/*
 * Catch That Cow
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 138279		Accepted: 42684
Description

Farmer John has been informed of the location of a fugitive cow and wants to catch her immediately. He starts at a point N (0 ≤ N ≤ 100,000) on a number line and the cow is at a point K (0 ≤ K ≤ 100,000) on the same number line. Farmer John has two modes of transportation: walking and teleporting.

* Walking: FJ can move from any point X to the points X - 1 or X + 1 in a single minute
* Teleporting: FJ can move from any point X to the point 2 × X in a single minute.

If the cow, unaware of its pursuit, does not move at all, how long does it take for Farmer John to retrieve it?

Input

Line 1: Two space-separated integers: N and K
Output

Line 1: The least amount of time, in minutes, it takes for Farmer John to catch the fugitive cow.
Sample Input

5 17
Sample Output

4
Hint

The fastest way for Farmer John to reach the fugitive cow is to move along the following path: 5-10-9-18-17, which takes 4 minutes.
Source

USACO 2007 Open Silver
 */

#include <iostream>
#include <queue>

using namespace std;

const int maxn = 100005;
bool vis[maxn];
int N, K;
int ans;

void bfs() {
    queue<int> que;
    que.push(N);
    que.push(-1);

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        // cout << "cur: " << cur << ", vis: " << (vis[cur] ? "true" : "false") << endl;
        if (cur == -1) {  // 注意，判断每层的结束标识之后再判断 vis
            ans++;
            if (!que.empty())
                que.push(-1);
            continue;
        }

        if (vis[cur])
            continue;
        vis[cur] = true;
        if (cur == K) break;


        if (cur - 1 >= 0 && !vis[cur - 1]) que.push(cur - 1);
        if (cur + 1 < maxn && !vis[cur + 1]) que.push(cur + 1);
        if (cur * 2 < maxn && !vis[2 * cur]) que.push(2 * cur);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> N >> K;
    bfs();
    cout << ans << endl;

    return 0;
}
