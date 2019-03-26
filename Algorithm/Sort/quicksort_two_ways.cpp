//
// Created by syh on 19-3-26.
//

// 快速排序

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
    int pivot = nums[low];
    int left = low + 1;
    int right = high;
    while (left <= right) { // 必须取等
        while (left <= right && nums[left] <= pivot) left++; // left 指向首个大于 pivot 的元素
        while (left <= right && nums[right] > pivot) right--; // right 指向最后一个小于等于 pivot 的元素
        if (left < right) // 否则元素与自身交换没有意义
            swap(nums[left], nums[right]);
    }
    swap(nums[right], nums[low]); // right 指向最后一个 小于等于 pivot 的元素
    return right;
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
