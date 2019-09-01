//
// Created by Yiheng Shu on 2019/8/31.
//

/**
Sample Input 1:

8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10

Sample Output 1:

2
AAA 3
GGG 3

Sample Input 2:

8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10

Sample Output 2:

0
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int nCalls, weiThre;
const int maxn = 2010;

class Edge {
public:
    int to;
    int w;

    Edge(int to, int w) : to(to), w(w) {}
};

vector<Edge> graph[maxn];
map<string, int> strToInt;
map<int, string> intToStr;
int nNode = 0;
int f[maxn];

void init() {
    for (int i = 0; i < maxn; i++) {
        f[i] = i;
    }
}

int find(int x) {
    int cur = x;
    while (x != f[x])
        x = f[x];

    int t;
    while (cur != x) {
        t = cur;
        f[cur] = x;
        cur = f[t];
    }
    return x;
}

void Union(int x, int y) {
    int fx = find(x);
    int fy = find(y);

    if (fx != fy) {
        f[fx] = fy;
    }
}

int convert(string str) {
    if (strToInt[str] == 0) {
        strToInt[str] = ++nNode;
        intToStr[strToInt[str]] = str;
    }
    return strToInt[str];
}

void input() {
    init();
    cin >> nCalls >> weiThre;
    string name1, name2;
    int time;
    for (int i = 0; i < nCalls; i++) {
        cin >> name1 >> name2 >> time;
        int n1 = convert(name1);
        int n2 = convert(name2);
        graph[n1].push_back(Edge(n2, time));
        graph[n2].push_back(Edge(n1, time));
        Union(n1, n2);
    }
}

struct Record {
    string name;
    int setCnt;

    Record(string name, int setCnt) : name(name), setCnt(setCnt) {}
};

bool nameCmp(const Record &a, const Record &b) {
    return a.name < b.name;
}

void solve() {
    int nComponents = 0;
    vector<Record> res;

    for (int i = 1; i <= nNode; i++) {
        if (f[i] == i) { // 并查集的根
            // 找头目和属于该类的成员数
            int setCnt = 0;     // 找到根，是该连通分量的第一个元素
            int setMinu = 0;
            int maxMinu = 0;
            int maxNode = 0;
            int nodeMinu = 0;

            for (int j = 1; j <= nNode; j++) {
                if (find(j) == i) {
                    setCnt++;
                    nodeMinu = 0;
                    for (int k = 0; k < graph[j].size(); k++) {
                        nodeMinu += graph[j][k].w;
                    }
                    if (nodeMinu > maxMinu) {
                        maxMinu = nodeMinu;
                        maxNode = j;
                    }
                    setMinu += nodeMinu;
                }
            }

            if (setMinu / 2 > weiThre && setCnt > 2) {
                // 将结果记录，遍历完后打印所有结果
                nComponents++;
                res.push_back(Record(intToStr[maxNode], setCnt));
            }
        }
    }

    if (!nComponents) {
        cout << nComponents;
        return;
    } else cout << nComponents << "\n";

    sort(res.begin(), res.end(), nameCmp);
    for (int i = 0; i < res.size(); i++) {
        if (i) cout << "\n";
        cout << res[i].name << " " << res[i].setCnt;
    }
}

int main() {
    input();
    solve();
    return 0;
}
