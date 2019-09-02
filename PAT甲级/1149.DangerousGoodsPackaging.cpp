//
// Created by Yiheng Shu on 2019/9/2.
//

#include <iostream>
#include <set>
#include <map>

using namespace std;

int n, m;
map<string, set<string> > incompatible;

int main() {
    cin >> n >> m;
    string str1, str2;
    for (int i = 0; i < n; i++) {
        cin >> str1 >> str2;
        incompatible[str1].insert(str2);
        incompatible[str2].insert(str1);
    }

    bool firstLine = true;
    int k;
    set<string> strSet;
    for (int i = 0; i < m; i++) {     // 货物检查
        bool solved = false;
        strSet.clear();
        cin >> k;
        for (int j = 0; j < k; j++) { // 输入一组货物
            cin >> str1;
            strSet.insert(str1);
        }
        for (set<string>::iterator j = strSet.begin(); j != strSet.end(); j++) {
            // 查找 strSet 中是否包含不兼容 *it 的货物
            set<string> &curSet = incompatible[*j];
            for (set<string>::iterator k = curSet.begin(); k != curSet.end(); k++) {
                if (strSet.find(*k) != strSet.end()) {
                    if (firstLine) firstLine = false;
                    else cout << "\n";
                    cout << "No";
                    solved = true;
                    break;
                }
            }
            if (solved) break;
        }
        if (!solved) {
            if (firstLine) firstLine = false;
            else cout << "\n";
            cout << "Yes";
        }
    }
    return 0;
}

