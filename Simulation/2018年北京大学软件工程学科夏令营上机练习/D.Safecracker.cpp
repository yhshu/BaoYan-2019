//
// Created by Yiheng Shu on 19-3-16.
//


// 五次循环不会超时
// 不要使用全排列，时间复杂度为阶乘级

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int power[28][6];

void init() {
    for (int i = 0; i <= 26; i++) {
        for (int j = 0; j <= 5; j++) {
            power[i][j] = (int) pow((long) i, j);
        }
    }
}

int main() {
    int num;
    string str;

    init();

    while (cin >> num >> str) {
        if (!num) break;
        vector<int> nums(str.size());
        for (int i = 0; i < str.size(); i++) {
            nums[i] = str[i] - 'A' + 1;
        }

        sort(nums.begin(), nums.end(), greater<int>());

        bool solved = false;

        for (int i1 = 0; i1 < nums.size(); ++i1) {
            for (int i2 = 0; i2 < nums.size(); ++i2) {
                if (i2 != i1)
                    for (int i3 = 0; i3 < nums.size(); ++i3) {
                        if (i3 != i1 && i3 != i2)
                            for (int i4 = 0; i4 < nums.size(); ++i4) {
                                if (i4 != i1 && i4 != i2 && i4 != i3)
                                    for (int i5 = 0; i5 < nums.size(); ++i5) {
                                        if (i5 != i1 && i5 != i2 && i5 != i3 && i5 != i4) {
                                            int sum = nums[i1] - power[nums[i2]][2]
                                                      + power[nums[i3]][3] - power[nums[i4]][4]
                                                      + power[nums[i5]][5];
                                            if (sum == num) {
                                                cout << char('A' + nums[i1] - 1) << char('A' + nums[i2] - 1)
                                                     << char('A' + nums[i3] - 1) << char('A' + nums[i4] - 1)
                                                     << char('A' + nums[i5] - 1) << endl;
                                                solved = true;
                                                break;
                                            }
                                        }
                                    }
                                if (solved) break;
                            }
                        if (solved) break;
                    }
                if (solved) break;
            }
            if (solved) break;
        }
        if (!solved) cout << "no solution" << endl;
    }
    return 0;
}