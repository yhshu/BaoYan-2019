//
// Created by Yiheng Shu on 2019/9/4.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int nStudents, nMid, nFinal;

class Student {
public:
    string name;
    int gp, gm, gf;
    double g;

    Student() {
        g = -1;
        gp = gm = gf = -1;
    }
};

map<string, Student> studentMap;
vector<Student> studentList;

int Round(double num) {
    if (num >= 0.0) return (num + 0.5);
    else return (num - 0.5);
}

bool cmp(const Student &a, const Student &b) {
    // 在比较前，应该先将以实数存储的最终成绩取整数
    if (a.g != b.g) return a.g > b.g;
    return a.name < b.name;
}

int main() {
    cin >> nStudents >> nMid >> nFinal;
    for (int i = 0; i < nStudents; i++) {
        string name;
        int gp;
        cin >> name >> gp;
        studentMap[name].name = name;
        studentMap[name].gp = gp;
    }

    for (int i = 0; i < nMid; i++) {
        string name;
        int gm;
        cin >> name >> gm;
        studentMap[name].name = name;
        studentMap[name].gm = gm;
    }

    for (int i = 0; i < nFinal; i++) {
        string name;
        int gf;
        cin >> name >> gf;
        studentMap[name].name = name;
        studentMap[name].gf = gf;
    }

    for (auto it = studentMap.begin(); it != studentMap.end(); it++) {
        // 根据作业、平时成绩和期末成绩，计算最终成绩，并将最终成绩取整数
        // 只需要输出及格的成绩，即最终成绩达到 60 分，并且在线编程达到 200 分
        Student &stu = it->second;
        int tgm = stu.gm >= 0 ? stu.gm : 0;
        int tgf = stu.gf >= 0 ? stu.gf : 0;
        if (tgm > tgf) stu.g = 0.4 * tgm + 0.6 * tgf;
        else stu.g = tgf;
        stu.g = (double) Round(stu.g);
        if (stu.g >= 60 && stu.gp >= 200)
            studentList.push_back(stu);
    }

    sort(studentList.begin(), studentList.end(), cmp);
    for (int i = 0; i < studentList.size(); i++) {
        if (i) cout << endl;
        Student &stu = studentList[i];
        printf("%s %d %d %d %.0lf", stu.name.c_str(), stu.gp, stu.gm, stu.gf, stu.g);
    }
    return 0;
}
