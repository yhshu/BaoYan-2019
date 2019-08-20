//
// Created by Yiheng Shu on 19-3-26.
//

// 快速排序 三指针分区法
// 类比单向扫描法，增加的是对小于、等于两种情况的区分

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 快速排序
 * @param nums 被排序数组
 * @param low 首个元素索引
 * @param high 末尾元素索引
 */
void quickSort(vector<int> &nums, int low, int high) {
    if (low < high) { // 不要忽略该判断，归并排序中也有类似判断
        int pivot = nums[low];
        int lt = low; // less than 指向首个不小于 pivot 的元素
        int i = low + 1; // pointer
        int gt = high; // greater than 指向最后一个不大于 pivot 的元素

        while (i <= gt) {
            if (nums[i] < pivot)
                swap(nums[i++], nums[lt++]);
            else if (nums[i] > pivot)
                swap(nums[i], nums[gt--]);
            else i++;
        }

        // lt 到 gt 之间的数都等于 pivot，不必再排序
        quickSort(nums, low, lt - 1);
        quickSort(nums, gt + 1, high);
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

    cout << nums[n / 2];
    return 0;
}
