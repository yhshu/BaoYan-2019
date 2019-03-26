//
// Created by syh on 19-3-26.
//

// 快速排序 一遍单向扫描法

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 将数组按 pivot 切分
 * @param nums 被切分数组，nums[high]为pivot
 * @param low 首个元素索引
 * @param high 末尾元素索引
 * @return pivot 索引
 */
int partition(vector<int> &nums, int low, int high) {
    int pivot = nums[high]; // 以最后一个元素为 pivot
    int i = low - 1; // i 及其前面的元素小于等于 pivot
    for (int j = low; j < high; j++) { // 注意在循环过程中，pivot 不应被交换
        if (nums[j] <= pivot)
            swap(nums[++i], nums[j]);
    }
    swap(nums[high], nums[i + 1]); // 交换 pivot 到合适位置
    return i + 1;
}

/**
 * 快速排序
 * @param nums 被排序数组
 * @param low 首个元素索引
 * @param high 末尾元素索引
 */
void quickSort(vector<int> &nums, int low, int high) {
    if (low < high) { // 不要忽略该判断，归并排序中也有类似判断
        int par = partition(nums, low, high);
        quickSort(nums, low, par - 1);
        quickSort(nums, par + 1, high);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    quickSort(nums, 0, n - 1); // 后两个参数是：首个元素的索引和末尾元素的索引

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
