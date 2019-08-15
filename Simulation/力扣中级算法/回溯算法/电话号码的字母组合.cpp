class Solution {
public:
    vector <string> letterCombinations(string digits) {
        map<char, string> kb; // keyboard
        kb['2'] = "abc";
        kb['3'] = "def";
        kb['4'] = "ghi";
        kb['5'] = "jkl";
        kb['6'] = "mno";
        kb['7'] = "pqrs";
        kb['8'] = "tuv";
        kb['9'] = "wxyz";

        vector <string> res;
        if (digits.empty()) return res;
        backtrack(kb, digits, res, "", 0);
        return res;
    }

    void backtrack(map<char, string> &kb, string digits, vector <string> &res, string cur, int i) {
        if (i == digits.size()) {
            res.push_back(cur);
            return;
        }

        for (int j = 0; j < kb[digits[i]].size(); j++) {
            backtrack(kb, digits, res, cur + kb[digits[i]][j], i + 1);
        }
    }
};