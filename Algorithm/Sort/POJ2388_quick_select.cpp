//
// Created by syh on 19-4-21.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * 在 nums[low...high] 中以线性时间快速选择第 k 小的数字
 * @param nums 数组
 * @param low 范围下界
 * @param high 范围上界
 * @param k 排序序号
 * @return nums[low...high] 中第 k 小的数字
 */
int quickSelect(vector<int> &nums, int low, int high, int k);

/**
 * 切分数组 nums[low...high]
 * @param nums 数组
 * @param left 范围下界
 * @param right 范围上界
 * @return
 */
int partition(vector<int> &nums, int low, int high);

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, t;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        nums.push_back(t);
    }

    cout << quickSelect(nums, 0, n - 1, n / 2);
    return 0;
}

int quickSelect(vector<int> &nums, int low, int high, int k) {
    if (low >= high)
        return nums[low];

    int pos = partition(nums, low, high);
    if (pos == k)
        return nums[pos];
    else if (pos > k) // 在左边子数组中查找
        return quickSelect(nums, low, pos - 1, k);
    return quickSelect(nums, pos + 1, high, k); // 在右子数组中查找
}

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
