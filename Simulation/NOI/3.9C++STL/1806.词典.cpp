//
// Created by Yiheng Shu on 19-3-28.
//

/*
 * 1806:词典
查看 提交 统计 提问
总时间限制: 3000ms 内存限制: 65536kB
描述
你旅游到了一个国外的城市。那里的人们说的外国语言你不能理解。不过幸运的是，你有一本词典可以帮助你。

输入
首先输入一个词典，词典中包含不超过100000个词条，每个词条占据一行。每一个词条包括一个英文单词和一个外语单词，两个单词之间用一个空格隔开。而且在词典中不会有某个外语单词出现超过两次。词典之后是一个空行，然后给出一个由外语单词组成的文档，文档不超过100000行，而且每行只包括一个外语单词。输入中出现单词只包括小写字母，而且长度不会超过10。
输出
在输出中，你需要把输入文档翻译成英文，每行输出一个英文单词。如果某个外语单词不在词典中，就把这个单词翻译成“eh”。
样例输入
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay
样例输出
cat
eh
loops
提示
输入比较大，推荐使用C语言的I / O函数。
来源
翻译自Waterloo local 2001.09.22的试题
 */

#include <bits/stdc++.h>

using namespace std;

map<string, string> mp;
char line[101], en[101], other[101];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while (gets(line) && line[0] != '\0') {
        sscanf(line, "%s%s", en, other);
        mp[other] = en;
    }
    while (gets(line) && line[0] != '\0') {
        if (mp.find(line) == mp.end())
            cout << "eh\n";
        else
            cout << mp[line] << "\n";
    }

    return 0;
}