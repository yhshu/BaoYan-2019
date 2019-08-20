//
// Created by Yiheng Shu on 2019-08-16.
//

// 本题考察排序

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n;  // 有分数的学生总数
int m;  // 查询成绩的学生总数

class Student {
public:
    string id;
    int c;
    int m;
    int e;
    int a;

    Student(const string& id, int c, int m, int e) :
            id(id), c(c), m(m), e(e) {
        a = c + m + e;
    }
};

const int inf = 0x3f3f3f3f;
vector<Student *> students;

Student *findStudent(const string &id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->id == id)
            return students[i];
    }
    return NULL;
}

void solve(const string &id) {
    vector<int> ranks(4, 1);
    Student *student = findStudent(id);
    if (student == NULL) {
        cout << "N/A";
        return;
    }

    for (int i = 0; i < students.size(); i++) { // 遍历所有学生，获得名次
        if (students[i]->a > student->a)
            ranks[0]++;
        if (students[i]->c > student->c)
            ranks[1]++;
        if (students[i]->m > student->m)
            ranks[2]++;
        if (students[i]->e > student->e)
            ranks[3]++;
    }

    int bestRank = inf;
    int bestRankType = -1;

    for (int i = 0; i < 4; i++) {
        if (ranks[i] < bestRank) {
            bestRank = ranks[i];
            bestRankType = i;
        }
    }

    if (bestRankType == 0) cout << bestRank << " " << "A";
    if (bestRankType == 1) cout << bestRank << " " << "C";
    if (bestRankType == 2) cout << bestRank << " " << "M";
    if (bestRankType == 3) cout << bestRank << " " << "E";

}

void input() {
    cin >> n >> m;
    string id;
    int cp, ma, en;
    for (int i = 0; i < n; i++) {
        cin >> id >> cp >> ma >> en;
        Student *student = new Student(id, cp, ma, en);
        students.push_back(student);
    }
    for (int i = 0; i < m; i++) {
        cin >> id;
        if (i) cout << "\n";
        solve(id);
    }
}

int main() {
    input();
    return 0;
}