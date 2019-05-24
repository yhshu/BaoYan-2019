/*
 * B:方便记忆的电话号码
查看 提交 统计 提问
总时间限制: 2000ms 内存限制: 65536kB
描述
英文字母（除Q和Z外）和电话号码存在着对应关系，如下所示：
A,B,C -> 2
D,E,F -> 3
G,H,I -> 4
J,K,L -> 5
M,N,O -> 6
P,R,S -> 7
T,U,V -> 8
W,X,Y -> 9
标准的电话号码格式是xxx-xxxx，其中x表示0-9中的一个数字。有时为了方便记忆电话号码，我们会将电话号码的数字转变为英文字母，如把263-7422记成America。有时，我们还加上“-”作为分隔符，如把449-6753记成Hi-World。当然，我们未必要将所有的数字都转变为字母，比如474-6635可以记成iPhone-5。
总之，一个方便记忆的电话号码由数字和除Q、Z外的英文字母组成，并且可以在任意位置插入任意多的“-”符号。
现在 ，我们有一个列表，记录着许多方便记忆的电话号码。不同的方便记忆的电话号码可能对应相同的标准号码，你的任务就是找出它们。


输入
第一行是一个正整数n（n <= 100000），表示列表中的电话号码数。
其后n行，每行是一个方便记忆的电话号码，它由数字和除Q、Z外的英文字母、“-”符号组成，其中数字和字母的总数一定为7，字符串总长度不超过200。
输出
输出包括若干行，每行包括一个标准电话号码（xxx-xxxx）以及它重复出现的次数k（k >= 2），中间用空格分隔。输出的标准电话号码需按照升序排序。

如果没有重复出现的标准电话号码，则输出一行“No duplicates.”。
样例输入
12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279
样例输出
310-1010 2
487-3279 4
888-4567 3
 */


// 仔细阅读题目，字母中的 'Q' 和 'Z' 被跳过

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

char charConvert(char ch) {
    if ('A' <= ch && ch <= 'O')
        return (ch - 'A') / 3 + '2';
    else if (ch == 'P' || ch == 'R' || ch == 'S')
        return '7';
    else if ('T' <= ch && ch <= 'V')
        return '8';
    else if ('W' <= ch && ch <= 'Y')
        return '9';
    return ch;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    map<string, int> phones;

    int n, len;
    string str;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str;
        len = 0;
        string phone;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == '-') continue;
            phone.push_back(charConvert(str[j]));
            if (phone.size() == 3)
                phone.push_back('-');
        }
        phones[phone]++;
    }

    bool duplicate = false;
    for (map<string, int>::iterator it = phones.begin(); it != phones.end(); it++) {
        if (it->second > 1) {
            duplicate = true;
            cout << it->first << " " << it->second << endl;
        }
    }
    if (!duplicate)
        cout << "No duplicates." << endl;

    return 0;
}
