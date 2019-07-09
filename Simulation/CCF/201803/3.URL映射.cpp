//
// Created by 舒意恒 on 2019-07-09.
//

/**
 * 问题描述

　 　URL 映射是诸如 Django、Ruby on Rails 等网页框架 (web frameworks) 的一个重要组件。对于从浏览器发来的 HTTP 请求，URL 映射模块会解析请求中的 URL 地址，并将其分派给相应的处理代码。现在，请你来实现一个简单的 URL 映射功能。
　 　本题中 URL 映射功能的配置由若干条 URL 映射规则组成。当一个请求到达时，URL 映射功能会将请求中的 URL 地址按照配置的先后顺序逐一与这些规则进行匹配。当遇到第一条完全匹配的规则时，匹配成功，得到匹配的规则以及匹配的参数。若不能匹配任何一条规则，则匹配失败。
　　本题输入的 URL 地址是以斜杠 / 作为分隔符的路径，保证以斜杠开头。其他合法字符还包括大小写英文字母、阿拉伯数字、减号 -、下划线 _ 和小数点 .。例如，/person/123/ 是一个合法的 URL 地址，而 /person/123? 则不合法（存在不合法的字符问号 ?）。另外，英文字母区分大小写，因此 /case/ 和 /CAse/ 是不同的 URL 地址。
　　对于 URL 映射规则，同样是以斜杠开始。除了可以是正常的 URL 地址外，还可以包含参数，有以下 3 种：
　　字符串 <str>：用于匹配一段字符串，注意字符串里不能包含斜杠。例如，abcde0123。
　　整数 <int>：用于匹配一个不带符号的整数，全部由阿拉伯数字组成。例如，01234。
　　路径 <path>：用于匹配一段字符串，字符串可以包含斜杠。例如，abcd/0123/。
　 　以上 3 种参数都必须匹配非空的字符串。简便起见，题目规定规则中 <str> 和 <int> 前面一定是斜杠，后面要么是斜杠，要么是规则的结束（也就是该参数是规则的最后一部分）。而 <path> 的前面一定是斜杠，后面一定是规则的结束。无论是 URL 地址还是规则，都不会出现连续的斜杠。

输入格式

　　输入第一行是两个正整数 n 和 m，分别表示 URL 映射的规则条数和待处理的 URL 地址个数，中间用一个空格字符分隔。
　　第 2 行至第 n+1 行按匹配的先后顺序描述 URL 映射规则的配置信息。第 i+1 行包含两个字符串 pi 和 ri，其中 pi 表示 URL 匹配的规则，ri 表示这条 URL 匹配的名字。两个字符串都非空，且不包含空格字符，两者中间用一个空格字符分隔。
　　第 n+2 行至第 n+m+1 行描述待处理的 URL 地址。第 n+1+i 行包含一个字符串 qi，表示待处理的 URL 地址，字符串中不包含空格字符。

输出格式

　　输入共 m 行，第 i 行表示 qi 的匹配结果。如果匹配成功，设匹配了规则 pj ，则输出对应的 rj。同时，如果规则中有参数，则在同一行内依次输出匹配后的参数。注意整数参数输出时要把前导零去掉。相邻两项之间用一个空格字符分隔。如果匹配失败，则输出 404。

样例输入

5 4
/articles/2003/ special_case_2003
/articles/<int>/ year_archive
/articles/<int>/<int>/ month_archive
/articles/<int>/<int>/<str>/ article_detail
/static/<path> static_serve
/articles/2004/
/articles/1985/09/aloha/
/articles/hello/
/static/js/jquery.js

样例输出

year_archive 2004
article_detail 1985 9 aloha
404
static_serve js/jquery.js

样例说明

　　对于第 1 个地址 /articles/2004/，无法匹配第 1 条规则，可以匹配第 2 条规则，参数为 2004。
　　对于第 2 个地址 /articles/1985/09/aloha/，只能匹配第 4 条规则，参数依次为 1985、9（已经去掉前导零）和 aloha。
　　对于第 3 个地址 /articles/hello/，无法匹配任何一条规则。
　　对于第 4 个地址 /static/js/jquery.js，可以匹配最后一条规则，参数为 js/jquery.js。

数据规模和约定

　　1 ≤ n ≤ 100，1 ≤ m ≤ 100。
　　所有输入行的长度不超过 100 个字符（不包含换行符）。
　　保证输入的规则都是合法的。
 */

#include <iostream>

using namespace std;

int n, m;  // URL 映射的规则条数和待处理的 URL 地址个数
const int maxn = 105;  // 数据规模
string rule[maxn];     // URL 路径规则
string resource[maxn]; // 资源名称
string request;        // URL 请求

bool valid(char ch) {
    return ('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == '-' || ch == '_' ||
           ch == '.' || ch == '/';
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> rule[i] >> resource[i];
    }
}

/**
 * 将请求匹配规则
 * @param rule 规则
 * @param request 请求
 * @param ctrl 控制标志：找到对应规则 0，输出资源和参数 1
 * @return 匹配成功 true，失败 false
 */
bool match(string &rule, string &request, int ctrl) {
    const int ruleLen = rule.size();
    const int requestLen = request.size();

    int ruleIdx = 0, requestIdx = 0;
    while (ruleIdx < ruleLen && requestIdx < requestLen) {
        if (rule[ruleIdx] == request[requestIdx]) { // 字符相同
            ruleIdx++;
            requestIdx++;
        } else {  // 字符不同
            if (rule[ruleIdx++] != '<')  // 不是 <int> <str> 或 <path> 的开始
                return false;            // 不匹配
            if (ctrl == 1)               // 为输出参数空格
                cout << " ";

            if (rule[ruleIdx] == 'i') {
                // 匹配 <int>
                bool leadingZero = true;
                bool ok = false;
                while (request[requestIdx] && request[requestIdx] != '/' &&
                       isdigit(request[requestIdx]) && valid(request[requestIdx])) {
                    ok = true;

                    // 去除前导 0，但题意不禁止一位 0
                    if (request[requestIdx] != '0')
                        leadingZero = false;  // 已不是前导 0

                    if (ctrl == 1 && !leadingZero) {
                        cout << request[requestIdx];
                    }
                }
                if (leadingZero)
                    return false;
                if (ok)  // 但 leadingZero 是 true，意味着参数是一位 0，它不是前导 0
                    cout << '0';

                ruleIdx += 4;            // 跳过 "<int>"

            } else if (rule[ruleIdx] == 's') {
                // 匹配 <str>，下个斜杠前或直到规则结束前是匹配的字符串
                bool ok = false;

                while (request[requestIdx] && request[requestIdx] != '/' && valid(request[requestIdx])) {
                    ok = true;
                    if (ctrl == 1)
                        cout << request[requestIdx];
                    requestIdx++;
                }
                if (!ok)
                    return false;       // 匹配失败

                ruleIdx += 4;            // 跳过 "<str>"

            } else if (rule[ruleIdx] == 'p') { // <path>
                if (ctrl == 1) {
                    // <path> 后一定是规则的结束，因此仅需输出请求的剩余部分
                    while (request[requestIdx]) {
                        cout << request[requestIdx++];
                    }
                }
                return true;
            }
        }
    }
}

void server() {
    for (int i = 0; i < m; i++) {     // 逐条处理请求
        cin >> request;
        bool found = false;           // 是否已找到资源
        for (int j = 0; j < n; j++) { // 逐条对比规则
            if (found)
                break;
            if (match(rule[j], request, 0)) {
                found = true;         // 找到匹配的规则
                cout << resource[j];  // 输出资源名
                match(rule[j], request, 1); // 输出参数
            }
        }
        if (!found)  // 没有找到匹配的规则
            cout << "404";
        cout << endl;
    }
}

int main() {
    input();  // 输入规则
    server(); // 处理请求，并输出结果

    return 0;
}
