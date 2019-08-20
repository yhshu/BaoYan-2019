// 1. 排序 时间复杂度 O(n logn)
// 2. 哈希表 时间复杂度 O(n)

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            map[s[i]]++;
            map[t[i]]--;
        }

        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] != 0)
                return false;
        }
        return true;
    }
};