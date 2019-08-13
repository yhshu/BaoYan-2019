// 对序列前一个数进行报数
// 数列第一项是1，第二项报第一项有1个1，即11
// 第三项报第二项，是2个1，即21
// 第四项报第三项，是1个2、1个1，即1211

// 本题可打表，时间复杂度 O(1)

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string num = "11";
        for (int i = 0; i < n - 2; i++) {
            num = countAndSay(num);
        }
        return num;
    }

    string countAndSay(string str) {
        stringstream ss;
        int cnt = 1;
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == str[i - 1]) {  // 如果当前字符与上一字符相同
                cnt++;
            } else {                    // 如果当前字符与上一字符不同
                ss << cnt << str[i - 1];
                cnt = 1;
            }

            if (i == str.size() - 1) {   // 如果是最后一个字符，输出当前计数
                ss << cnt << str[i];
            }
        }
        string res;
        ss >> res;
        // cout << "countAndSay(" << str << ") " << res << endl;
        return res;
    }
};

