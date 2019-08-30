//
// Created by Yiheng Shu on 2019/8/30.
//

/*
Sample Input:

2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85

Sample Output:

9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxk = 310;

int n;
int cnt;
int last[maxk]; // last[i] 是第 i 台测试机的上一个测试记录索引，用于计算 local_rank
int testLen[maxk];

class Test {
public:
    string number;
    int score;
    int location;
    int localRank;
    int finalRank;

    Test(string number, int score, int location) : number(number), score(score), location(location) {}
};

bool operator<(const Test &a, const Test &b) {
    if (a.score != b.score) return a.score > b.score;
    return a.number < b.number;  // 这是一个测试点
}

vector<Test> testList;

void input() {
    cin >> n;
    int k;
    string number;
    int score;

    for (int i = 1; i <= n; i++) {
        cin >> k;
        cnt += k;
        for (int j = 1; j <= k; j++) {
            cin >> number >> score;
            testList.push_back(Test(number, score, i));
        }
    }
}

void solve() {
    sort(testList.begin(), testList.end());

    fill(last, last + maxk, -1);
    int len = 1;
    testList[0].finalRank = 1;
    testList[0].localRank = 1;
    testLen[testList[0].location] = 1;
    last[testList[0].location] = 0;

    for (int i = 1; i < testList.size(); i++) {
        Test &curTest = testList[i];
        if (curTest.score == testList[i - 1].score) {
            curTest.finalRank = testList[i - 1].finalRank;
            len++;
        } else {
            curTest.finalRank = testList[i - 1].finalRank + len;
            len = 1;
        }

        int &lastIdx = last[curTest.location];
        if (lastIdx == -1) {
            lastIdx = i;
            curTest.localRank = 1;
            testLen[curTest.location] = 1;
        } else {
            if (testList[lastIdx].score == curTest.score) {
                curTest.localRank = testList[lastIdx].localRank;
                testLen[curTest.location]++;
            } else {
                curTest.localRank = testList[lastIdx].localRank + testLen[curTest.location];
                testLen[curTest.location] = 1;
            }
            lastIdx = i;
        }
    }
}

void output() {
    cout << cnt << endl;
    for (int i = 0; i < testList.size(); i++) {
        if (i) cout << endl;
        cout << testList[i].number << " " << testList[i].finalRank << " "
             << testList[i].location << " " << testList[i].localRank;
    }
}

int main() {
    input();
    solve();
    output();
    return 0;
}
