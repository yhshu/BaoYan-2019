//
// Created by syh on 19-5-25.
//

/*
 * 1088:滑雪
查看 提交 统计 提示 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
输入
输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
输出
输出最长区域的长度。
样例输入
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
样例输出
25
来源
Don't know
 */

#include <iostream>

using namespace std;
const int maxn = 105;
const int dir[][2] = {{-1, 0},
                      {1,  0},
                      {0,  1},
                      {0,  -1}};
int m, n;
int nums[maxn][maxn];
int len[maxn][maxn];

/**
 * 递推
 * @param i 横坐标
 * @param j 纵坐标
 * @return 从当前位置开始的最长下降距离
 */
int dp(int i, int j) {
    if (len[i][j])
        return len[i][j];
    int res = 0;
    for (int k = 0; k < 4; k++) {
        int tx = i + dir[k][0];
        int ty = j + dir[k][1];
        if (tx >= 0 && tx < m && ty >= 0 && ty < n && nums[i][j] > nums[tx][ty]) {
            res = max(res, dp(tx, ty));
        }
    }
    len[i][j] = res + 1;
    return res + 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> m >> n;
    int ans = -1;
    // 输入
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }

    // 动态规划
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            len[i][j] = dp(i, j);
            //  cout << len[i][j];
            ans = max(ans, len[i][j]);
        }
        //cout << endl;
    }

    // 输出
    cout << ans << endl;
    return 0;
}