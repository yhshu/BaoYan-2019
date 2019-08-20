class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        while (i < j) {  // 取等没有意义
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            cout << i << " " << j << endl;
            if (tolower(s[i++]) != tolower(s[j--]))
                return false;
        }
        return true;
    }
};