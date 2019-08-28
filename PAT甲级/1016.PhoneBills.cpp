//
// Created by Yiheng Shu on 2019/8/28.
//

/*
一个长途电话公司根据以下规则向客户收费：
打长途电话在每分钟需要花费一定费用，取决于打电话的时间。
当一个顾客开始连接长途电话时，开始计时；挂掉电话时，结束计时。每个自然月，账单被发给顾客。

 */

#include <iostream>
#include <vector>

using namespace std;

class Time {
public:
    int month;
    int day;
    int hour;
    int minute;
};

class Record {
public:
    string name;
    Time time;
    int mode;
};

int rates[30];
int n;
vector<Record> records;

void input() {
    for (int i = 0; i < 24; i++) {
        cin >> rates[i];
    }
    cin >> n;
    string mode;
    for (int i = 0; i < n; i++) {
        Record record;
        cin >> record.name;
        scanf("%d:%d:%d:%d", &record.time.month, &record.time.day, &record.time.hour, &record.time.minute);
        cin >> mode;
        if (mode == "on-line") record.mode = 1;
        else record.mode = 0;
        records.push_back(record);
    }
}

void solve() {

}

int main() {
    input();
    solve();
    return 0;
}