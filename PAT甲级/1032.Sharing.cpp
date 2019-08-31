//
// Created by Yiheng Shu on 2019/8/31.
//

#include <iostream>
#include <map>

using namespace std;

int addr1, addr2, n;
const int max_addr = 100010;

class Node {
public:
    int addr;
    char data;
    int next;

    Node() {}

    Node(int addr, char data, int next) : addr(addr), data(data), next(next) {}
};

Node mem[max_addr];
bool vis[max_addr];
bool solved = false;

void input() {
    cin >> addr1 >> addr2 >> n;
    int addr, next;
    char data;
    for (int i = 0; i < n; i++) {
        cin >> addr >> data >> next;
        Node node(addr, data, next);
        mem[addr] = node;
    }
}

void solve() {
    // 遍历第一条链表，对每个节点做标记
    int cur = addr1;
    while (cur != -1) {
        vis[mem[cur].addr] = true;
        cur = mem[cur].next;
    }

    // 遍历第二条链表，找到第一个被标记的节点
    cur = addr2;
    while (cur != -1) {
        if (vis[mem[cur].addr]) {
            solved = true;
            printf("%05d", mem[cur].addr);
            return;
        }
        cur = mem[cur].next;
    }

    if (!solved) cout << -1;
}

int main() {
    input();
    solve();
    return 0;
}