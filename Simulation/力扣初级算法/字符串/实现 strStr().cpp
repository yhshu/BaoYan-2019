class Solution {
public:
    /**
     * 字符串匹配
     * @param haystack 文本串
     * @param needle 模式串
     * @return 匹配的字符串在文本串中的首位索引，匹配失败返回 -1
     */
    int strStr(string haystack, string needle) {
        vector<int> next = buildNext(needle);
        int n = haystack.size(), i = 0;
        int m = needle.size(), j = 0;

        while (i < n && j < m) {
            if (j < 0 || haystack[i] == needle[j]) { // 匹配，注意 j < 0 的条件
                i++;
                j++;
            } else {                                 // 失配
                j = next[j];
            }
        }
        return (j == m) ? i - j : -1;
    }

    /**
     * 构建 next 数组
     * 模式串自匹配
     * @param needle 模式串
     * @return next 数组
     */
    vector<int> buildNext(string needle) {
        int m = needle.size(), j = 0;
        vector<int> next(m + 5);

        int t = next[0] = -1;            // 模式串指针，p[-1] 通配符
        while (j < m - 1) {
            if (t < 0 || needle[j] == needle[t]) { // 匹配，注意 t < 0 的条件
                next[++j] = ++t;
            } else                       // 失配
                t = next[t];
        }
        return next;
    }
};
