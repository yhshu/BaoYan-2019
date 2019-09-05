//
// Created by Yiheng Shu on 2019/9/5.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int total, skip, firstId;
vector<string> forwards;
unordered_set<string> vis;

int main() {

    cin >> total >> skip >> firstId;
    for (int i = 0; i < total; i++) {
        string str;
        cin >> str;
        forwards.push_back(str);
    }

    int id = firstId;
    while (id <= forwards.size()) {
        string name = forwards[id - 1];
        if (vis.find(name) == vis.end()) {
            vis.insert(name);
            printf("%s\n", name.c_str());
            id += skip;
        } else {
            id++;
        }
    }

    if (vis.empty()) {
        printf("Keep going...");
    }

    return 0;
}