#include <iostream>
#include <cstdio>

using namespace std;

int n;
const int maxn = 10010;
int a[maxn];
int b[maxn];
int g[maxn];
int k[maxn];
int x, y;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }
    cin >> x >> y;
    
    int ans = -1;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] <= x && x <= a[i] + g[i] && b[i] <= y && y <= b[i] + k[i]) {
            ans = i + 1;
            break;
        }
    }
    cout << ans;
    return 0;
}
