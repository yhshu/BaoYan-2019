#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> > pq;

    int n;
    cin >> n;
    int t;
    for(int i = 0; i < n; i++) {
        cin >> t;
        pq.push(t);
    }

    long long ans = 0; // int is not ok, long long is necessary
    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        ans += a + b;
        pq.push(a + b);
    }
    cout << ans;
    return 0;
}
