//
// Created by Yiheng Shu on 2019/9/1.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int nCards, nQueries;

const int maxn = 10010;
const int maxm = 110;

struct Record {
    string id;
    int score;

    Record() {}
};

bool cmp(const Record &a, const Record &b) {
    if (a.score != b.score) return a.score > b.score;
    return a.id < b.id;
}

Record records[maxn];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> nCards >> nQueries;

    for (int i = 0; i < nCards; i++) {
        cin >> records[i].id >> records[i].score;
    }

    int queryType;
    string queryTerm;
    for (int i = 1; i <= nQueries; i++) {
        cin >> queryType >> queryTerm;
        bool queryFirst = true;
        bool solved = false;
        if (i > 1) printf("\n");
        printf("Case %d: %d %s\n", i, queryType, queryTerm.c_str());

        if (queryType == 1) {
            sort(records, records + nCards, cmp);
            for (int j = 0; j < nCards; j++) {
                if (records[j].id.substr(0, 1) == queryTerm) {
                    if (queryFirst) queryFirst = false;
                    else printf("\n");
                    printf("%s %d", records[j].id.c_str(), records[j].score);
                    solved = true;
                }
            }
        } else if (queryType == 2) {
            int queryCnt = 0;
            int scoreSum = 0;
            for (int j = 0; j < nCards; j++) {
                if (records[j].id.substr(1, 3) == queryTerm) {
                    queryCnt++;
                    scoreSum += records[j].score;
                    solved = true;
                }
            }
            if (solved) printf("%d %d", queryCnt, scoreSum);
        } else if (queryType == 3) {
            map<string, int> res;
            for (int j = 0; j < nCards; j++) {
                if (records[j].id.substr(4, 6) == queryTerm) {
                    string curStr = records[j].id.substr(1, 3);
                    res[curStr]++;
                    solved = true;
                }
            }
            if (solved) {
                vector<Record> resRecords;
                for (map<string, int>::iterator it = res.begin(); it != res.end(); it++) {
                    Record record;
                    record.id = it->first;
                    record.score = it->second;
                    resRecords.push_back(record);
                }
                sort(resRecords.begin(), resRecords.end(), cmp);
                for (int i = 0; i < resRecords.size(); i++) {
                    if (i) printf("\n");
                    printf("%s %d", resRecords[i].id.c_str(), resRecords[i].score);
                }
            }
        }

        if (!solved) printf("NA");
    }

    return 0;
}
