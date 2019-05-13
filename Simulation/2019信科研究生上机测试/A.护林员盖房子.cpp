//
// Created by syh on 19-5-10.
//

/*
 * A:护林员盖房子
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
在一片保护林中，护林员想要盖一座房子来居住，但他不能砍伐任何树木。
现在请你帮他计算：保护林中所能用来盖房子的矩形空地的最大面积。

输入
保护林用一个二维矩阵来表示，长宽都不超过20（即<=20）。
第一行是两个正整数m,n，表示矩阵有m行n列。
然后是m行，每行n个整数，用1代表树木，用0表示空地。
输出
一个正整数，表示保护林中能用来盖房子的最大矩形空地面积。
样例输入
4 5
0 1 0 1 1
0 1 0 0 1
0 0 0 0 0
0 1 1 0 1
样例输出
5
提示
子矩阵边长可以为1，也就是说：
0 0 0 0 0
依然是一个可以盖房子的子矩阵。
来源
2017医学部计算概论-期末考试-申博
 */

#include <iostream>

using namespace std;

const int maxn = 25;
int nums[maxn][maxn];

// 扫描线法 求最大空地面积
// 使用三个数组
// h[i, j] 表示点 (i, j) 对应的悬线长度
// left[i, j] 表示点 (i, j) 对应的悬线左边界
// right[i, j] 表示点 (i, j) 对应的悬线右边界

// 从上向下扫描，从左到右计算 left 数组，从右到左计算 right 数组，并更新答案
// 在实现中，数组降维以节约空间

int h[maxn], l[maxn], r[maxn];
int lb, rb;
int ans = 0;

int main() {
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }

    for (int j = 0; j < n; j++) {
        h[j] = 0;
        l[j] = 0;
        r[j] = n;
    }

    for (int i = 0; i < m; i++) {
        lb = -1;
        rb = n;
        for (int j = 0; j < n; j++) { // 从左到右扫描
            if (nums[i][j] == 1) {  // 该点是障碍
                h[j] = 0;
                l[j] = 0;
                lb = j;
            } else {  // 该点是空地
                h[j]++;
                l[j] = max(l[j], lb + 1);
            }
        }
        for (int j = n - 1; j >= 0; j--) { // 从右到左扫描
            if (nums[i][j] == 1) {  // 该点是障碍
                r[j] = n;
                rb = j;
            } else {  // 该点是空地
                r[j] = min(r[j], rb - 1);
                ans = max(ans, h[j] * (r[j] - l[j] + 1));
                //cout << h[j] << " " << r[j] << " " <<l[j] <<endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
