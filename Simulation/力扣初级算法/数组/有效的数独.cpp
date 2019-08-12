// 一个部分填充的有效数独不一定是可解的，本题只需验证已经填入的数字是否有效
// 本题的问题规模是给定的，所以时间复杂度 O(1)，空间复杂度 O(1)
// 需要考虑尽量简洁有效的方法

// 1.暴力方法是对于每个数字，检查行、列、九宫格中是否有重复的数字
// 2.使用哈希表，一次遍历

// 注意如何从坐标 (i, j) 得到九宫格的序号: i / 3 * 3 + j / 3，其中的除法是整数除法

class Solution {
public:
    bool isValidSudoku(vector <vector<char>> &board) {
        unordered_map<int, int> row[15];  // 记录每行数字出现的次数
        unordered_map<int, int> col[15];  // 记录每列数字出现的次数
        unordered_map<int, int> cube[15]; // 记录每个九宫格中数字出现的次数

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int cur = board[i][j];
                if (cur != '.') { // 如果该位置是数字，判断有效
                    row[i][cur]++;
                    col[j][cur]++;
                    cube[i / 3 * 3 + j / 3][cur]++;
                }

                if (row[i][cur] > 1 || col[j][cur] > 1 || cube[i / 3 * 3 + j / 3][cur] > 1)
                    return false;
            }
        }

        return true;
    }
};
