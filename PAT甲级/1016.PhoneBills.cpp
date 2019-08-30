//
// Created by Yiheng Shu on 2019/8/28.
//

/*
一个长途电话公司根据以下规则向客户收费：
打长途电话在每分钟需要花费一定费用，取决于打电话的时间。
当一个顾客开始连接长途电话时，开始计时；挂掉电话时，结束计时。每个自然月，账单被发给顾客。
 */

/*
Sample Input:

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line

Sample Output:

CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80

 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int rates[30];

class Time {
public:
    int month;
    int day;
    int hour;
    int minute;

    bool operator<(const Time &t) const {
        if (month != t.month) return month < t.month;
        if (day != t.day) return day < t.day;
        if (hour != t.hour) return hour < t.hour;
        if (minute != t.minute) return minute < t.minute;
    }

    int convertToMinute() const {
        return 24 * 60 * day + 60 * hour + minute;
    }

    int delta(const Time &t) const {
        return abs(convertToMinute() - t.convertToMinute());
    }

    /**
     * 跳到下一分钟，返回当前这一分钟的费用
     * @return
     */
    int nextMinute() {
        int fee = rates[hour];
        minute += 1;
        if (minute == 60) {
            minute = 0;
            hour += 1;
            if (hour == 24) {
                hour = 0;
                day += 1;
            }
        }
        return fee;
    }
};

class Record {
public:
    string name;
    Time time;
    int mode;
};

class BillItem {
public:
    Time startTime;
    Time endTime;
    int duration;
    double itemAmount;

    void print() {
        printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f", startTime.day, startTime.hour, startTime.minute,
               endTime.day, endTime.hour, endTime.minute, duration, itemAmount);
    }

    bool operator<(const BillItem &billItem) const {
        return startTime < billItem.startTime;
    }

    BillItem(Time startTime, Time endTime) : startTime(startTime), endTime(endTime) {
        duration = startTime.delta(endTime);

        // itemAmount
        itemAmount = 0;
        Time t = startTime;
        while (t.delta(endTime) != 0) {
            itemAmount += t.nextMinute();
        }
        itemAmount /= 100;
    }
};

class Bill {
public:
    string name;
    int month;
    vector<BillItem> billTerms;

    double getTotalAmount() {
        double res = 0;
        for (int i = 0; i < billTerms.size(); i++) {
            res += billTerms[i].itemAmount;
        }
        return res;
    }

    void print() {
        if (billTerms.empty()) return;
        cout << name << " ";
        printf("%02d\n", month);
        sort(billTerms.begin(), billTerms.end());
        for (int i = 0; i < billTerms.size(); i++) {
            if (billTerms[i].duration == 0) continue;
            billTerms[i].print();
            printf("\n");
        }
        printf("Total amount: $%.2f", getTotalAmount());
    }
};

int n;
vector<Record> records;
map<string, stack<Record> > recordStacks;
vector<Bill> bills;

Bill &findBill(string name) {
    for (int i = 0; i < bills.size(); i++) {
        if (bills[i].name == name)
            return bills[i];
    }
    Bill bill;
    bill.name = name;
    bills.push_back(bill);
    return findBill(name);
}


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

bool timeCmp(const Record &a, const Record &b) {
    return a.time < b.time;
}

void solve() {
    sort(records.begin(), records.end(), timeCmp);  // 按时间排序
    for (int i = 0; i < records.size(); i++) {
        Record &record = records[i];
        if (record.mode == 1)
            recordStacks[record.name].push(record);
        else if (!recordStacks[record.name].empty()) {
            Record prevRecord = recordStacks[record.name].top();
            recordStacks[record.name].pop();

            if (prevRecord.time.delta(record.time)) {
                Bill &bill = findBill(record.name);
                bill.month = record.time.month;
                BillItem billItem(prevRecord.time, record.time);
                bill.billTerms.push_back(billItem);
            }
        }
    }
}

bool nameCmp(const Bill &a, const Bill &b) {
    return a.name < b.name;
}

void output() {
    sort(bills.begin(), bills.end(), nameCmp);
    for (int i = 0; i < bills.size(); i++) {
        if (i)printf("\n");
        bills[i].print();
    }
}

int main() {
    // todo
    input();
    solve();
    output();
    return 0;
}