//
// Created by Yiheng Shu on 19-4-9.
//

/*
 * E:重要逆序对
查看 提交 统计 提问
总时间限制: 10000ms 单个测试点时间限制: 1000ms 内存限制: 65536kB
描述
给定N个数的序列a1,a2,...aN，定义一个数对(ai, aj)为“重要逆序对”的充要条件为 i < j 且 ai > 2aj。求给定序列中“重要逆序对”的个数。

输入
第一行为序列中数字的个数N（1 ≤ N ≤ 200000）。
第二行为序列a1, a2 ... aN(0 ≤a ≤ 10000000)，由空格分开。
输出
输出一个整数，为给序列中“重要逆序对”的个数。
样例输入
10
0 9 8 7 6 5 4 3 2 1
样例输出
16
提示
如果使用printf输出long long类型，请用%lld
数据范围
对于40%的数据，有N ≤ 1000。
 */

// 计算重要逆序对只需要对归并排序解法做简单的更改，但排序和求逆序对数需要分离

#include <bits/stdc++.h>

using namespace std;

long long ans; // 重要逆序对的数量，题目暗示使用 long long

/**
 * 计算逆序对数
 *
 * @param nums
 * @param left
 * @param mid
 * @param right
 */
void mergeCnt(vector<int> &nums, int left, int mid, int right) {
    // 创建临时数组
    vector<int> L;
    vector<int> R;

    for (int i = left; i <= mid; i++)
        L.push_back(nums[i]);
    for (int j = mid + 1; j <= right; j++)
        R.push_back(nums[j]);

    int i = 0, j = 0, k = left;
    int l1 = mid - left + 1, l2 = right - mid;
    // 合并两数组，注意排序的规则在本题中：不是单纯地比较原始数组中两数字的大小
    while (i < l1 && j < l2) {
        if (L[i] <= 2 * R[j]) {
            nums[k++] = L[i++];
        } else {
            ans += (l1 - i);
            nums[k++] = R[j++];
        }
    }

    while (i < l1) nums[k++] = L[i++];
    while (j < l2) nums[k++] = R[j++];
}

/**
 * 归并左右两数组
 *
 * @param nums
 * @param left
 * @param mid
 * @param right
 */
void merge(vector<int> &nums, int left, int mid, int right) {
    // 创建临时数组
    vector<int> L;
    vector<int> R;

    for (int i = left; i <= mid; i++)
        L.push_back(nums[i]);
    for (int j = mid + 1; j <= right; j++)
        R.push_back(nums[j]);

    int i = 0, j = 0, k = left;
    int l1 = mid - left + 1, l2 = right - mid;
    // 合并两数组，注意排序的规则在本题中：不是单纯地比较原始数组中两数字的大小
    while (i < l1 && j < l2) {
        if (L[i] <= R[j])
            nums[k++] = L[i++];
        else
            nums[k++] = R[j++];

    }

    while (i < l1) nums[k++] = L[i++];
    while (j < l2) nums[k++] = R[j++];
}

/**
 * 递归实现的归并排序
 *
 * @param nums
 * @param left
 * @param right
 */
void mergeSort(vector<int> &nums, int left, int right) {
    if (left < right) { // 注意判断
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid); // 闭区间[left, mid]
        mergeSort(nums, mid + 1, right); // 闭区间[mid + 1, right]
        mergeCnt(nums, left, mid, right);
        merge(nums, left, mid, right);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    vector<int> nums;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }

    mergeSort(nums, 0, nums.size() - 1);

    cout << ans;
    return 0;
}
