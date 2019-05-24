/*
B:单词翻转
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入一个句子（一行），将句子中的每一个单词翻转后输出。

输入
只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。
输出
翻转每一个单词后的字符串，单词之间的空格需与原文一致。
样例输入
hello world
样例输出
olleh dlrow
*/


// 注意，仅单词翻转，空格原样输出，输入仅有一行

#include <iostream>
#include <string>

using namespace std;

int main() {
    int wordBegin = 0;
    string str;
    getline(cin, str);
    int len = str.size();

    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') { // 读到空格，表示单词结束，除最后一个单词外
            for (int j = i - 1; j >= wordBegin; j--) { // 逆序输出单词
                cout << str[j];
            }
            cout << " "; // 单词后空格
            wordBegin = i + 1;
        }
        if (i == len - 1) { // 最后一个单词
            for (int j = i; j >= wordBegin; j--) {
                cout << str[j];
            }
        }
    }
    return 0;
}
