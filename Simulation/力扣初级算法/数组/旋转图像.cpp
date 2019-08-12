// 顺时针 90 度旋转一个方阵
// 本题限定空间复杂度 O(1) 完成
// 最优的时间复杂度是 O(n^2)

// 以下的实现思路：转置，翻转每一行

class Solution {
public:
    void rotate(vector <vector<int>> &mat) {
        const int n = mat.size();

        // 遍历整个上三角，转置
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // 翻转每一行
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                // cout << i << " " << j << endl;
                swap(mat[i][j], mat[i][n - 1 - j]);
            }
        }
    }
};