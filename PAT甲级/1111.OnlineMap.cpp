//
// Created by Yiheng Shu on 2019/9/19.
//

#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int n, m;
int src, dest;
int cnt;
const int maxn = 510;
int head[maxn];
const int inf = 0x3f3f3f3f;

int dis1[maxn];
int ttime1[maxn];

int dis2[maxn];
int ttime2[maxn];

int dispre1[maxn];
int timepre1[maxn];

int dispre2[maxn];
int timepre2[maxn];
int timecnt[maxn];

int disStack[maxn];
int timeStack[maxn];

int disStackCnt = 0;
int timeStackCnt = 0;

struct Edge {
    int from;
    int to;
    int length;
    int time;
    int next;
};
Edge e[maxn * maxn];
bool vis[maxn];

void addEdge(int v1, int v2, int length, int time) {
    cnt++;
    e[cnt].from = v1;
    e[cnt].to = v2;
    e[cnt].length = length;
    e[cnt].time = time;
    e[cnt].next = head[v1];
    head[v1] = cnt;
}

struct DisNode {
    int to;
    int dis;
    int time;

    bool operator<(const DisNode &DisNode) const {
        if (dis != DisNode.dis) return dis > DisNode.dis;
        return time > DisNode.time;
    }
};


void disDijkstra() {
    for (int i = 0; i < maxn; i++) {
        dispre1[i] = timepre1[i] = -1;
        dis1[i] = ttime1[i] = inf;
        vis[i] = false;
        timecnt[i] = inf;
    }
    timecnt[src] = dis1[src] = ttime1[src] = 0;

    priority_queue<DisNode> pq;
    DisNode startNode;
    startNode.dis = startNode.time = 0;
    startNode.to = src;
    pq.push(startNode);

    while (!pq.empty()) {
        DisNode cur = pq.top();
        pq.pop();

        if (vis[cur.to]) continue;
        vis[cur.to] = true;

        for (int i = head[cur.to]; i; i = e[i].next) {
            Edge &edge = e[i];
            if (dis1[edge.to] > dis1[cur.to] + edge.length) {
                dis1[edge.to] = dis1[cur.to] + edge.length;
                ttime1[edge.to] = ttime1[cur.to] + edge.time;
                dispre1[edge.to] = cur.to;

                DisNode disnode;
                disnode.to = edge.to;
                disnode.dis = dis1[edge.to];
                disnode.time = ttime1[edge.to];
                pq.push(disnode);
            } else if (dis1[edge.to] == dis1[cur.to] + edge.length) {
                if (ttime1[edge.to] > ttime1[cur.to] + edge.time) {
                    ttime1[edge.to] = ttime1[cur.to] + edge.time;
                    dispre1[edge.to] = cur.to;
                }
            }
        }
    }
}

struct TimeNode {
    int to;
    int dis;
    int time;

    bool operator<(const TimeNode &timenode) const {
        if (time != timenode.time) return time > timenode.time;
        return dis > timenode.dis;
    }
};

bool judgeEqual() {
    if (timeStackCnt != disStackCnt) return false;
    for (int i = 0; i < timeStackCnt; i++) {
        if (timeStack[i] != disStack[i]) return false;
    }
    return true;
}

void timeDijkstra() {
    for (int i = 0; i < maxn; i++) {
        dispre2[i] = timepre2[i] = -1;
        dis2[i] = ttime2[i] = inf;
        timecnt[i] = inf;
        vis[i] = false;
    }
    timecnt[src] = dis2[src] = ttime2[src] = 0;

    priority_queue<TimeNode> pq;
    TimeNode startNode;
    startNode.dis = startNode.time = 0;
    startNode.to = src;
    pq.push(startNode);

    while (!pq.empty()) {
        TimeNode cur = pq.top();
        pq.pop();

        if (vis[cur.to]) continue;
        vis[cur.to] = true;

        for (int i = head[cur.to]; i; i = e[i].next) {
            Edge &edge = e[i];
            if (ttime2[edge.to] > ttime2[cur.to] + edge.time) {
                ttime2[edge.to] = ttime2[cur.to] + edge.time;
                dis2[edge.to] = dis2[cur.to] + edge.length;
                timecnt[edge.to] = timecnt[cur.to] + 1;
                timepre2[edge.to] = cur.to;

                TimeNode timenode;
                timenode.to = edge.to;
                timenode.dis = dis2[edge.to];
                timenode.time = ttime2[edge.time];
                pq.push(timenode);
            } else if (ttime2[edge.to] == ttime2[cur.to] + edge.time) {
                if (timecnt[edge.to] > timecnt[cur.to] + 1) {
                    timecnt[edge.to] = timecnt[cur.to] + 1;
                    dis2[edge.to] = dis2[cur.to] + edge.length;
                    timepre2[edge.to] = cur.to;
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v1, v2, oneway, length, time;
        cin >> v1 >> v2 >> oneway >> length >> time;
        addEdge(v1, v2, length, time);
        if (oneway == 0)
            addEdge(v2, v1, length, time);
    }
    cin >> src >> dest;

    disDijkstra();
    timeDijkstra();

    int cur = dest;
    while (cur != src) {
        disStack[disStackCnt++] = cur;
        cur = dispre1[cur];
    }

    cur = dest;
    while (cur != src) {
        timeStack[timeStackCnt++] = cur;
        cur = timepre2[cur];
    }

    bool equal = judgeEqual();
    if (!equal) {
        printf("Distance = %d: %d", dis1[dest], src);
        for (int i = disStackCnt - 1; i >= 0; i--) {
            printf(" -> %d", disStack[i]);
        }
        printf("\n");
        printf("Time = %d: %d", ttime2[dest], src);
        for (int i = timeStackCnt - 1; i >= 0; i--) {
            printf(" -> %d", timeStack[i]);
        }
    } else {
        printf("Distance = %d; Time = %d: %d", dis2[dest], ttime2[dest], src);
        for (int i = timeStackCnt - 1; i >= 0; i--) {
            printf(" -> %d", timeStack[i]);
        }
    }
    return 0;
}