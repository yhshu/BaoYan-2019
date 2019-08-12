// 线性扫描两次，第一次统计出现次数，第二次判断是否是唯一字符

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> map;
        for (char c: s) {
            map[c]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};