//
// Created by Yiheng Shu on 2019/9/5.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<double, vector<double>, greater<double>> nums;
    for (int i = 0; i < n; i++) {
        double num;
        cin >> num;
        nums.push(num);
    }

    while (nums.size() > 1) {
        int a = nums.top();
        nums.pop();
        int b = nums.top();
        nums.pop();

        int sum = a + b;
        sum /= 2;
        nums.push(sum);
    }
    cout << nums.top();
    return 0;
}