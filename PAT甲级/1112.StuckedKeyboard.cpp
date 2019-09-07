//
// Created by Yiheng Shu on 2019/9/6.
//

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

map<char, int> charMap;
int k;
string str;

int main() {
    cin >> k >> str;
    int len = 1;
    int pos;
    for (pos = 1; pos < str.size(); pos++) {
        if (str[pos] == str[pos - 1]) {
            len++;
        } else {
            if (len % k != 0)
                charMap[str[pos - 1]] = 1;
            else if (len % k == 0 && charMap[str[pos - 1]] != 1)
                charMap[str[pos - 1]] = 2;
            len = 1;
        }
    }
    if (len % k == 0 && charMap[str[pos - 1]] != 1) {
        charMap[str[pos - 1]] = 2;
    }

    set<char> s;
    vector<char> res;
    for (int i = 0; i < str.size(); i++) {
        if (charMap[str[i]] == 2 && s.find(str[i]) == s.end()) {
            res.push_back(str[i]);
            s.insert(str[i]);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        printf("%c", res[i]);
    }
    printf("\n");
    for (int i = 0; i < str.size();) {
        printf("%c", str[i]);
        if (s.find(str[i]) != s.end())
            i += k;
        else i++;
    }

    return 0;
}
