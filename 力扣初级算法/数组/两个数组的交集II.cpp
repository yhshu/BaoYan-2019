// 两个数组排序后，双指针分别指向两个数组，判断元素是否相等

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        if (nums1.empty() || nums2.empty())
            return res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return res;
    }
};