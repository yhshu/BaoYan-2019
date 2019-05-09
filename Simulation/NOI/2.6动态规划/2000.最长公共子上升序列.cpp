/*
2000:最长公共子上升序列
查看 提交 统计 提问
总时间限制: 10000ms 内存限制: 65536kB
描述
给定两个整数序列，写一个程序求它们的最长上升公共子序列。
当以下条件满足的时候，我们将长度为N的序列S1 , S2 , . . . , SN 称为长度为M的序列A1 , A2 , . . . , AM 的上升子序列：

存在 1 <= i1 < i2 < . . . < iN <= M ，使得对所有 1 <= j <=N，均有Sj = Aij，且对于所有的1 <= j < N，均有Sj < Sj+1。

输入
每个序列用两行表示，第一行是长度M(1 <= M <= 500)，第二行是该序列的M个整数Ai (-231 <= Ai < 231 )
输出
在第一行，输出两个序列的最长上升公共子序列的长度L。在第二行，输出该子序列。如果有不止一个符合条件的子序列，则输出任何一个即可。
样例输入
5
1 4 2 5 -12
4
-12 1 2 4
样例输出
2
1 4
*/


#include <iostream>
#include <vector>

using namespace std;

class Sol {
public:
    int len;
    vector<int> nums;

    Sol() {
        len = 0;
    }
};

const int maxn = 510;

int nums1[maxn], nums2[maxn];
Sol dp[maxn];

int main() {
    int len1, len2;

    cin >> len1;
    for (int i = 0; i < len1; i++)
        cin >> nums1[i];
    cin >> len2;
    for (int i = 0; i < len2; i++)
        cin >> nums2[i];

    for (int i = 0; i < len2; i++) {
        Sol maxSol;
        for (int j = 0; j < len1; j++) {
            if (nums1[j] < nums2[i] && dp[j].len > maxSol.len)
                maxSol = dp[j];
            if (nums1[j] == nums2[i]) {
                dp[j].len = maxSol.len + 1;
                dp[j].nums = maxSol.nums;
                dp[j].nums.push_back(nums2[i]);
            }
            cout << nums1[j] << " " << nums2[i] << " " << dp[j].len << endl;
        }
    }

    Sol maxSol = dp[0];
    for (int i = 1; i < len1; i++)
        if (dp[i].len > maxSol.len)
            maxSol = dp[i];
    cout << maxSol.len << endl;

    for (int i = 0; i < maxSol.nums.size(); i++)
        cout << maxSol.nums[i] << " ";
    cout << endl;

    return 0;
}
