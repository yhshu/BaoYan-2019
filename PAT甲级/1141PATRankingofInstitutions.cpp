#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 10010;

class School {
public:
    int rank;
    string name;
    double tws;
    int ns;
};

map<string, School> schoolMap;
vector<School> schoolList;

School &findSchool(string name) {
    if (schoolMap.find(name) == schoolMap.end()) {
        School school;
        school.rank = school.tws = school.ns = 0;
        school.name = name;
        schoolMap[name] = school;
    }
    return schoolMap[name];
}

bool scoreCmp(const School &a, const School &b) {
    if (a.tws != b.tws) return a.tws > b.tws;
    if (a.ns != b.ns) return a.ns < b.ns;
    return a.name < b.name;
}

void tolower(string &str) {
    for (int i = 0; i < str.size(); i++) {
        if (isupper(str[i])) {
            str[i] += 'a' - 'A';
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string id;
        int score;
        string schoolName;
        cin >> id >> score >> schoolName;
        tolower(schoolName);

        School &school = findSchool(schoolName);
        school.ns++;
        if (id[0] == 'B')
            school.tws += score / 1.5;
        else if (id[0] == 'A')
            school.tws += score;
        else if (id[0] == 'T')
            school.tws += score * 1.5;
    }

    for (map<string, School>::iterator it = schoolMap.begin(); it != schoolMap.end(); it++) {
        School &school = it->second;
        int t = (int) school.tws;
        school.tws = (double) t;
        schoolList.push_back(school);
    }
    sort(schoolList.begin(), schoolList.end(), scoreCmp);

    int len = 1;
    schoolList[0].rank = 1;
    for (int i = 1; i < (int) schoolList.size(); i++) {
        if (schoolList[i].tws == schoolList[i - 1].tws) {
            schoolList[i].rank = schoolList[i - 1].rank;
            len++;
        } else {
            schoolList[i].rank = schoolList[i - 1].rank + len;
            len = 1;
        }
    }

    cout << schoolList.size();
    if (!schoolList.empty()) {
        cout << endl;
        for (int i = 0; i < (int) schoolList.size(); i++) {
            if (i) cout << endl;
            School &school = schoolList[i];
            cout << school.rank << " " << school.name << " " << school.tws << " " << school.ns;
        }
    }

    return 0;
}