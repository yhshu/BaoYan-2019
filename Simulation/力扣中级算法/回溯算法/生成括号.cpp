class Solution {
public:
    vector <string> generateParenthesis(int n) {
        vector <string> res;
        if (!n) return res;

        generateParenthesis(res, "", n, 0, 0);
        return res;
    }

    void generateParenthesis(vector <string> &res, string str, int n, int open, int close) {
        if (str.size() == 2 * n) {
            res.push_back(str);
            return;
        }

        if (open < n) {
            generateParenthesis(res, str + "(", n, open + 1, close);
        }
        if (close < open) {
            generateParenthesis(res, str + ")", n, open, close + 1);
        }
    }
};