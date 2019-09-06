//
// Created by Yiheng Shu on 2019/9/6.
//

#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int nCouple, nGuest;
unordered_map<int, int> couple;
unordered_set<int> guests;
set<int> single;
bool firstspace = true;

void nextspace() {
    if (firstspace)
        firstspace = false;
    else printf(" ");
}

int main() {
    cin >> nCouple;
    for (int i = 0; i < nCouple; i++) {
        int a, b;
        cin >> a >> b;
        couple[a] = b;
        couple[b] = a;
    }

    cin >> nGuest;
    for (int i = 0; i < nGuest; i++) {
        int guest;
        cin >> guest;
        guests.insert(guest);
    }

    for (auto it = guests.begin(); it != guests.end(); it++) {
        if (couple.find(*it) == couple.end() || guests.find(couple[*it]) == guests.end()) {
            single.insert(*it);
        }
    }

    bool firstspace = true;
    printf("%d", single.size());
    if (!single.empty()) printf("\n");
    for (auto it = single.begin(); it != single.end(); it++) {
        if (firstspace) firstspace = false;
        else printf(" ");

        printf("%05d", *it);  // 填充前导 0 是给分点
    }

    return 0;
}
