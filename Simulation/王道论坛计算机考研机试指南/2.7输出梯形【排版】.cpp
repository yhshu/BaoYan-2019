#include <iostream>

using namespace std;

int main() {
    int h;
    cin >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < 2 * (h - i - 1); j++)
            cout << " ";
        for (int j = 0; j < 2 * i + h; j++)
            cout << "*";
        cout << endl;
    }
    return 0;
}
