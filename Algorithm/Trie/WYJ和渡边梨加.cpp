//
// Created by Yiheng Shu on 19-4-23.
//

// 2019年东北大学建龙钢铁大学生程序设计竞赛 F题
// 前缀树

/*
 * Problem Description
WYJ最近很喜欢日本的偶像小姐姐，但是由于日本人总是喜欢用姓来称呼人，当WYJ喜欢的日本偶像小姐姐过多的时候，会分不清哪个是哪个，比如说偶像组合AKB48的一位成员叫渡边麻友，欅坂46的一位成员叫渡边梨加，日向坂46又有个成员叫渡边美穗，当他和一个日本人聊到渡边梨加时，就想知道和渡边梨加名字很像的小姐姐有哪几个来防止搞混。这里WYJ为了简化问题，只需要让你告诉他有几个就可以了。WYJ现在希望聪明的读者你来解决一下这个很简单的问题：

给你一共n个WYJ喜欢的日本偶像小姐姐的姓名，每个小姐姐的姓名是仅由不超过m个小写字母（没有大写字母，数字和空格）组成的一个字符串(n*m<=400000)，WYJ想知道对于每个小姐姐，与她有着最长相同姓名前缀的其他小姐姐有多少个？

Input
第一行一个数字k（k<=10），表示有k组数据。

对于每组数据，第一行为一个数字n，表示姓名字符串的数量，

接下来的n行，每一行有一个长度不超过m的字符串

其中对于每组数据，有n*m<=400000

Output
对于每一组数据，输出n行，每一行一个数字，表示相应字符串的对应答案

Sample Input
2
3
watanabemayu
watanaberika
watanabemiho
3
mayuyu
penopenopenope
pepepenope
Sample Output
1
2
1
0
1
1
Source
lby
数据规模较大，请使用scanf，printf
前缀是指一个字符串从第一个字符开始的若干个字符所组成的字符串
Hint
No Hint!
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

const int CHARSET = 26, BASE = 'a', MAX_NODE = 400000;

struct Trie {
    int tot, root;
    int child[MAX_NODE][CHARSET];
    int flag[MAX_NODE];
    map<int *, int> resmp;

    Trie() {
        memset(child[1], 0, sizeof(child[1]));
        flag[1] = 0;
        root = tot = 1;
    }

    void insert(const char *str) {
        int *cur = &root;
        for (const char *p = str; *p; ++p) {
            cur = &child[*cur][*p - BASE];
            resmp[cur]++;
            if (*cur == 0) {
                *cur = ++tot;
                memset(child[tot], 0, sizeof(child[tot]));
                flag[tot] = false;
            }
        }
        flag[*cur] = true;
    }

    int query(const char *str, int &res, int &sol) {
        int *cur = &root;
        for (const char *p = str; *p && *cur; ++p) {
            cur = &child[*cur][*p - BASE];
            if (resmp[cur] > 1) {
                res = min(res, resmp[cur]);
                sol = 1;
            }
            //cout << "res:" <<res << endl;
        }
        res--;
        return (*cur && flag[*cur]);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int k;
    string name;
    int n;

    cin >> k;
    vector<string> str;
    while (k--) {
        cin >> n;
        Trie *t = new Trie();
        while (n--) {
            cin >> name;
            t->insert(name.c_str());
            str.push_back(name.c_str());
        }
        for (int i = 0; i < str.size(); i++) {
            int res = str[i].size();
            int sol = 0;
            int check = t->query(str[i].c_str(), res, sol);
            // cout << "check: " <<check<<endl;
            if (sol)
                cout << res << endl;
            else cout << 0 << endl;
        }
        delete t;
        str.clear();
    }
    return 0;
}
