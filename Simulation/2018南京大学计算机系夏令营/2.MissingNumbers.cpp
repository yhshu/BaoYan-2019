/*
 * 2. Missing number

Given a positive integer n(n≤40), pick n-1 numbers randomly from 1 to n and concatenate them in random order as a string s,
 which means there is a missing number between 1 and n.
 Can you find the missing number? (Notice that in some cases the answer will not be unique,
 and in these cases you only need to find one valid answer.）

Examples:
Input:

20
81971112205101569183132414117

Output:
16

 */

// 本题需要找到 1 ~ n 中唯一缺失的数，输入的数字以字符串形式直接拼接，而不是数组的形式

#include <iostream>

using namespace std;

const int maxn = 45;
int n;
string str;
bool vis[maxn];

void input() {
    cin >> n;   // 字符串长度
    cin >> str; // 输入字符串
}

void dfs(string &str, int i) {
    if (i == str.size()) {  // 搜索结束，返回答案
        for (int j = 1; j <= n; j++) {
            if (!vis[j])    // 输出没有出现过的数字
                cout << j;
        }
        return;
    }

    if (str[i] == '0') {  // 一位和两位整数都不可能以 0 开头，题目要求 1 ~ n
        return;
    }

    // 当前是 1 位数字
    if (str[i] - '0' <= n && !vis[str[i] - '0']) {
        vis[str[i] - '0'] = true;  // 访问
        dfs(str, i + 1);      // 搜索到下一位
        vis[str[i] - '0'] = false; // 恢复标志位
    }

    // 当前是 2 位数字的开始
    if (i < str.size() - 1) {
        int num = (str[i] - '0') * 10 + str[i + 1] - '0';  // 两位数
        if (num <= n && !vis[num]) {
            vis[num] = true;
            dfs(str, i + 2);
            vis[num] = false;
        }
    }
}

int main() {
    input();
    dfs(str, 0);
    return 0;
}