//
// Created by Yiheng Shu on 2019/8/30.
//

// 玩家在空余的桌子中选择最小编号的桌子，如果所有桌子已满则必须在队列中等待，每对玩家最多可以玩 2 小时。
// 本题 1. 统计每个人在队列中的等待时间 2. 统计每桌服务了多少玩家。
// 问题的难点是，俱乐部为 VIP 预留座位。当一个 VIP 桌开放，队列中的第一组 VIP 玩家将有机会享受该桌服务。
// 如果队列中没有 VIP，第一对玩家可以享受服务。如果有 VIP 玩家而没有 VIP 座位，他们与普通玩家一样被调度。

#include <iostream>
#include <vector>

using namespace std;

const int maxk = 105;

int nPlayers;  // 玩家对数
int nTables;   // 桌子数量
int nvipTables;// VIP 桌数
bool vipTables[maxk];

class Player {
public:
    int hour;
    int minute;
    int second;
    int playTime;
    int vip;

    Player(int hour, int minute, int second, int playTime, int vip) :
            hour(hour), minute(minute), second(second), playTime(playTime), vip(vip) {}
};

vector<Player> players;

bool operator<(const Player &a, const Player &b) {
    if (a.hour != b.hour) return a.hour < b.hour;
    if (a.minute != b.minute) return a.minute < b.minute;
    if (a.second != b.second) return a.second < b.second;
}

void input() {
    cin >> nPlayers;
    int hour, minute, second, playTime, vip;
    for (int i = 0; i < nPlayers; i++) {
        scanf("%d:%d:%d %d %d", &hour, &minute, &second, &playTime, &vip);
        Player player(hour, minute, second, player, vip);
        players.push_back(player);
    }
    cin >> nTables >> nvipTables;
    int table;
    for (int i = 0; i < nvipTables; i++) {
        cin >> table;
        vipTables[table] = true;
    }
}

void solve() {
    sort(players.begin(), players.end());

    // todo
}

int main() {
    input();
    solve();
    return 0;
}