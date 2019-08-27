//
// Created by Yiheng Shu on 2019/8/27.
//

/*
Sample Input:

3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40

Sample Output:

SC3021234 CS301133
*/

#include <iostream>

using namespace std;

int n;
string ans1, ans2;

class Time {
public:
    int h;
    int m;
    int s;

    Time() { h = m = s = 0; }

    Time(int h, int m, int s) : h(h), m(m), s(s) {}
};

Time minStart(24, 0, 0);
Time maxEnd(0, 0, 0);

bool operator<(const Time &t1, const Time &t2) {
    if (t1.h < t2.h) return true;
    if (t1.h > t2.h)return false;
    if (t1.m < t2.m) return true;
    if (t1.m > t2.m) return false;
    if (t1.s < t2.s) return true;
    return false;
}

bool operator>(const Time &t1, const Time &t2) {
    if (t1.s == t2.s && t1.h == t2.h && t1.m == t2.m) return false;
    return !(t1 < t2);
}

class Record {
public:
    string id;
    Time start;
    Time end;

    Record() {}
};

void input() {
    cin >> n;
    string id;
    int h, m, s;
    for (int i = 0; i < n; i++) {
        cin >> id;
        Record record;
        scanf("%d:%d:%d %d:%d:%d", &record.start.h, &record.start.m, &record.start.s,
              &record.end.h, &record.end.m, &record.end.s);

        if (record.start < minStart) {
            minStart = record.start;
            ans1 = id;
        }
        if (record.end > maxEnd) {
            maxEnd = record.end;
            ans2 = id;
        }
    }
}

void output() {
    cout << ans1 << " " << ans2;
}

int main() {
    input();
    output();
    return 0;
}