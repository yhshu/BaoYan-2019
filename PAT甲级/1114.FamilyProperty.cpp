//
// Created by Yiheng Shu on 2019/9/7.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

const int maxn = 10010;
int f[maxn];
bool valid[maxn];
bool firstline = true;

void nextline() {
    if (firstline) firstline = false;
    else printf("\n");
}

struct Family {
    int root;
    int cnt;
    double m;
    double familyArea;
};

bool cmp(const Family &a, const Family &b) {
    double averageArea1 = a.familyArea / a.cnt;
    double averageArea2 = b.familyArea / b.cnt;
    if (averageArea1 != averageArea2) return averageArea1 > averageArea2;
    return a.root < b.root;
}

unordered_map<int, Family> familyMap;
vector<Family> familyList;
double mEstate[maxn];
double area[maxn];

void init() {
    for (int i = 0; i < maxn; i++)
        f[i] = i;
}

int find(int x) {
    while (x != f[x])
        x = f[x];
    return x;
}

void makeValid(int x) {
    if (x == -1) return;
    valid[x] = true;
}

int Union(int x, int y) {
    if (x == -1 || y == -1) return -1;
    int fx = find(x);
    int fy = find(y);

    if (fx > fy) f[fx] = fy;
    else if (fx < fy) f[fy] = fx;
    return min(fx, fy);
}

int main() {
    int nLine;
    cin >> nLine;

    init();
    for (int lineIdx = 0; lineIdx < nLine; lineIdx++) {
        int id, fa, mo, nChild;
        cin >> id >> fa >> mo >> nChild;
        makeValid(id);
        makeValid(fa);
        makeValid(mo);
        Union(id, fa);
        Union(id, mo);

        for (int childIdx = 0; childIdx < nChild; childIdx++) {
            int child;
            cin >> child;
            makeValid(child);
            Union(id, child);
        }
        cin >> mEstate[id] >> area[id];
    }

    int nComponent = 0;
    for (int i = 0; i < maxn; i++) {
        if (!valid[i]) continue;
        int fi = find(i);
        if (fi == i) {
            nComponent++;
            familyMap[fi].root = i;
        }
        familyMap[fi].cnt++;
        familyMap[fi].m += mEstate[i];
        familyMap[fi].familyArea += area[i];
    }
    printf("%d", nComponent);
    if (nComponent) printf("\n");

    for (auto it = familyMap.begin(); it != familyMap.end(); it++)
        familyList.push_back(it->second);

    sort(familyList.begin(), familyList.end(), cmp);
    for (auto it = familyList.begin(); it != familyList.end(); it++) {
        nextline();
        printf("%04d %d %.3lf %.3lf", it->root, it->cnt, it->m / it->cnt, it->familyArea / it->cnt);
    }
    return 0;
}
