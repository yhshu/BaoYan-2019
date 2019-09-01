//
// Created by Yiheng Shu on 2019/9/1.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
const int maxn = 1010;
int nums[maxn];
int heap; // 0 Not Heap; 1 Min Heap; 2 Max Heap

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    if (nums[1] >= nums[2] && nums[1] >= nums[3]) heap = 2;
    else if (nums[1] <= nums[2] && nums[1] <= nums[3]) heap = 1;
    else heap = 0;
}

void print(const vector<int> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        if (i)cout << " ";
        cout << vec[i];
    }
}

void dfs(int idx, vector<int> path) {
    path.push_back(nums[idx]);
    if (idx * 2 > n) {
        print(path);
        cout << endl;
        if (heap) {
            for (int i = 1; i < path.size(); i++) {
                if (path[i - 1] >= path[i] && heap == 1) {
                    heap = 0;
                    break;
                } else if (path[i - 1] <= path[i] && heap == 2) {
                    heap = 0;
                    break;
                }
            }
        }
        return;
    }
    if (idx * 2 + 1 <= n)
        dfs(idx * 2 + 1, path);
    if (idx * 2 <= n)
        dfs(idx * 2, path);
}

void solve() {
    vector<int> path;
    dfs(1, path);
    // 输出大根堆或小根堆
    if (heap == 2) cout << "Max Heap";
    else if (heap == 1) cout << "Min Heap";
    else cout << "Not Heap";
}


int main() {
    input();
    solve();
    return 0;
}
