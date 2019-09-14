//
// Created by Yiheng Shu on 2019/9/14.
//

#include <iostream>
#include <cstdio>

using namespace std;

int nStu, nDelete;

struct Node {
    int val;
    Node *prev;
    Node *next;

    Node(int val) : val(val) { prev = next = NULL; }
};

const int maxn = 100010;
Node *nodes[maxn];
bool valid[maxn];

Node *head;

Node *findNode(int val) {
    Node *node = nodes[val];
    if (node != NULL && valid[val]) return node;
    return NULL;
}

void del(Node *node) {
    if (node == NULL) return;
    valid[node->val] = false;
    Node *p = node->prev;
    Node *n = node->next;
    if (p) p->next = n;
    if (n) n->prev = p;
    delete node;
}

void insertBefore(Node *node, int val) {
    Node *b = node->prev;
    valid[val] = true;
    Node *newNode = new Node(val);
    nodes[val] = newNode;
    newNode->prev = b;
    newNode->next = node;
    if (b)
        b->next = newNode;
    node->prev = newNode;
    if (head == node) {
        head = newNode;
    }
    valid[val] = true;
}

void insertAfter(Node *node, int val) {
    Node *n = node->next;
    valid[val] = true;
    Node *newNode = new Node(val);
    nodes[val] = newNode;
    newNode->prev = node;
    newNode->next = n;
    if (n)
        n->prev = newNode;
    node->next = newNode;
}

int main() {
    cin >> nStu;
    nodes[1] = head = new Node(1);
    valid[1] = true;

    for (int i = 2; i <= nStu; i++) {
        int stu, p;
        cin >> stu >> p;
        Node *node = findNode(stu);
        nodes[stu] = node;
        if (p == 0) { // 插入到 stu 左边
            insertBefore(node, i);
        } else {        // 插入到 stu 右边
            insertAfter(node, i);
        }
    }

    cin >> nDelete;
    for (int i = 0; i < nDelete; i++) {
        // 找到要删除的节点
        int d;
        cin >> d;
        Node *cur = findNode(d);
        del(cur);
    }

    Node *cur = head;
    while (cur) {
        printf("%d ", cur->val);
        cur = cur->next;
    }

    return 0;
}