//
// Created by Yiheng Shu on 2019/9/6.
//

#include <iostream>
#include <map>
#include <cmath>

using namespace std;

const int maxn = 10010;
map<int, int> rankMap;
int checked[maxn];
bool firstline = true;

void nextline() {
    if (firstline) firstline = false;
    else printf("\n");
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num + 0.5); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int nContestant, nQuery;

    cin >> nContestant;
    for (int i = 1; i <= nContestant; i++) {
        int num;
        cin >> num;
        rankMap[num] = i;
    }
    cin >> nQuery;
    for (int i = 0; i < nQuery; i++) {
        int query;
        cin >> query;
        nextline();

        if (rankMap.find(query) == rankMap.end()) {
            printf("%04d: Are you kidding?", query);
            continue;
        }
        int rank = rankMap[query];
        if (checked[query]) {
            printf("%04d: Checked", query);
            continue;
        }
        checked[query] = true;
        if (rank == 1) printf("%04d: Mystery Award", query);
        else if (isPrime(rank)) printf("%04d: Minion", query);
        else printf("%04d: Chocolate", query);
    }

    return 0;
}