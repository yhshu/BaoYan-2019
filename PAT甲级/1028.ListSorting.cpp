//
// Created by Yiheng Shu on 2019/8/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nLine, col;

class Student {
public:
    string id;
    string name;
    int grade;

    Student(string id, string name, int grade) : id(id), name(name), grade(grade) {}
};

vector<Student> students;

void input() {
    cin >> nLine >> col;
    string id, name;
    int grade;
    for (int i = 0; i < nLine; i++) {
        cin >> id >> name >> grade;
        Student student(id, name, grade);
        students.push_back(student);
    }
}

bool idCmp(const Student &a, const Student &b) {
    return a.id < b.id;
}

bool nameCmp(const Student &a, const Student &b) {
    if (a.name != b.name) return a.name < b.name;
    return a.id < b.id;
}

bool gradeCmp(const Student &a, const Student &b) {
    if (a.grade != b.grade) return a.grade < b.grade;
    return a.id < b.id;
}

void solve() {
    if (col == 1) sort(students.begin(), students.end(), idCmp);
    if (col == 2) sort(students.begin(), students.end(), nameCmp);
    if (col == 3) sort(students.begin(), students.end(), gradeCmp);
}

void output() {
    for (int i = 0; i < students.size(); i++) {
        if (i) cout << endl;
        cout << students[i].id << " " << students[i].name << " " << students[i].grade;
    }
}

int main() {
    input();
    solve();
    output();
    return 0;
}
