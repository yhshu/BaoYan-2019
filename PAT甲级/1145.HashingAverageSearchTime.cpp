//
// Created by Yiheng Shu on 2019/9/3.
//

#include <iostream>
#include <cmath>

using namespace std;

const int maxn = 10010;
int tableSize, nInput, nKey;
int table[maxn];
bool firstline = true;

bool judgePrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i < sqrt(num + 0.5); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void redefine() {
    while (!judgePrime(tableSize)) {
        tableSize++;
    }
}

void nextline() {
    if (firstline) firstline = false;
    else cout << endl;
}

int Hash(int key) {
    for (int i = 0; i < tableSize; i++) {
        int probing = (key + i * i) % tableSize;
        if (table[probing] == 0)
            return probing;
    }
    return -1;  // 无法插入
}

void insert(int num) {
    int key = Hash(num);
    if (key == -1) {
        nextline();
        cout << num << " cannot be inserted.";
    } else {
        table[key] = num;
    }
}

void input() {
    cin >> tableSize >> nInput >> nKey;
    redefine();
    for (int i = 0; i < nInput; i++) {
        int t;
        cin >> t;
        insert(t);
    }
}

void query() {
    double search = 0;
    for (int i = 0; i < nKey; i++) {
        int t;
        cin >> t;
        for (int j = 0; j <= tableSize; j++) {
            search++;
            int probing = (t + j * j) % tableSize;
            if (table[probing] == t || table[probing] == 0)
                break;
        }
    }
    nextline();
    printf("%.1lf", search / nKey);
}

int main() {
    input();
    query();
    return 0;
}