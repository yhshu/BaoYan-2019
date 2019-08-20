//
// Created by Yiheng Shu on 2019-08-19.
//

/*
Sample Input:

3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla

Sample Output:

1: The Testing Book
1111111
2222222
2: Yue Chen
1111111
3333333
3: keywords
1111111
2222222
3333333
4: ZUCS Print
1111111
5: 2011
1111111
2222222
3: blablabla
Not Found

 */

#include <iostream>
#include <algorithm>  // macOS C++ 98 不引入 algorithm 编译通过，OJ 上无法编译通过
#include <vector>
#include <map>

using namespace std;

int n;  // 书的数量，小于 1e4
int m;  // 查询数量，小于 1000

map<string, vector<string> > titleMap;
map<string, vector<string> > authorMap;
map<string, vector<string> > keywordsMap;
map<string, vector<string> > publisherMap;
map<string, vector<string> > publishYearMap;

bool printMap(map<string, vector<string> > &bookMap, string mapKey) {
    if (bookMap[mapKey].empty()) return false;
    vector<string> &vec = bookMap[mapKey];
    sort(vec.begin(), vec.end());  // 题目要求按升序输出

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    return true;
}

void solve() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    string id, title, author, keywords, publisher, publishYear;
    getline(cin, id);  // 读掉换行

    for (int i = 0; i < n; i++) {
        getline(cin, id);

        getline(cin, title);
        titleMap[title].push_back(id);

        getline(cin, author);
        authorMap[author].push_back(id);

        getline(cin, keywords);
        // 将关键词按空格分割
        int pos, len;
        for (pos = 0, len = 0; pos < keywords.size(); pos++) {
            if (keywords[pos] == ' ') {
                keywordsMap[keywords.substr(pos - len, len)].push_back(id);
                len = 0;
            } else {
                len++;
            }
        }
        keywordsMap[keywords.substr(pos - len, len)].push_back(id);

        getline(cin, publisher);
        publisherMap[publisher].push_back(id);

        getline(cin, publishYear);
        publishYearMap[publishYear].push_back(id);
    }

    // 假设每本书只属于一个作者，关键字在5个以内，总共不超过1000个关键字
    // 不超过1000个不同的出版社

    cin >> m;
    string query, key;
    getline(cin, query);  // 读掉换行
    for (int i = 0; i < m; i++) {
        getline(cin, query);
        int pos;
        for (pos = 0; pos < query.size(); pos++) {
            if (query[pos] == ' ') break;
        }
        key = query.substr(pos + 1, query.size() - pos - 1);
        cout << query << endl;
        bool found = false;
        if (query[0] == '1') found = printMap(titleMap, key);
        if (query[0] == '2') found = printMap(authorMap, key);
        if (query[0] == '3') found = printMap(keywordsMap, key);
        if (query[0] == '4') found = printMap(publisherMap, key);
        if (query[0] == '5') found = printMap(publishYearMap, key);
        if (!found) cout << "Not Found" << endl;
    }
}

int main() {
    solve();
    return 0;
}
