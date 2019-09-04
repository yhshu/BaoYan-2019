//
// Created by Yiheng Shu on 2019/9/4.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

string startAddr;
int nNode, k;

class Node {
public:
    string addr;
    int data;
    string next;
};

unordered_map<string, Node> nodeMap;
vector<Node> nodeList;
bool firstline = true;

void nextline() {
    if (firstline) firstline = false;
    else printf("\n");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> startAddr >> nNode >> k;

    for (int i = 0; i < nNode; i++) {
        string addr;
        int data;
        string next;
        cin >> addr >> data >> next;
        nodeMap[addr].addr = addr;
        nodeMap[addr].data = data;
        nodeMap[addr].next = next;
    }

    string addr = startAddr;
    while (addr != "-1") {
        Node &node = nodeMap[addr];
        nodeList.push_back(node);
        addr = node.next;
    }

    vector<Node> newNodeList(nodeList.size());
    int cnt = 0;
    for (int i = 0; i < nodeList.size(); i++)
        if (nodeList[i].data < 0)
            newNodeList[cnt++] = nodeList[i];
    for (int i = 0; i < nodeList.size(); i++)
        if (0 <= nodeList[i].data && nodeList[i].data <= k)
            newNodeList[cnt++] = nodeList[i];
    for (int i = 0; i < nodeList.size(); i++)
        if (nodeList[i].data > k)
            newNodeList[cnt++] = nodeList[i];

    for (int i = 0; i < newNodeList.size(); i++) {
        nextline();
        printf("%s %d ", newNodeList[i].addr.c_str(), newNodeList[i].data);
        if (i < newNodeList.size() - 1) printf("%s", newNodeList[i + 1].addr.c_str());
        else printf("-1");
    }

    return 0;
}
