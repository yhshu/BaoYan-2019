//
// Created by Yiheng Shu on 2019/9/13.
//

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int maxn = 110;
int n;
char board[maxn][maxn];
int dx[10] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[10] = {-1, -1, -1, 0, 0, 1, 1, 1};

bool judge(char ch) {
    return ch == 'y' || ch == 'i' || ch == 'z' || ch == 'h' || ch == 'o' || ch == 'n' || ch == 'g';
}

const string target = "yizhong";

struct Node {
    int x;
    int y;
};

Node path[10];
char res[maxn][maxn];

void dfs(int x, int y, int step, int dir) {
    if (step == 6) {
        for (int i = 0; i < target.size() - 1; i++) {
            Node node = path[i];
            res[node.x][node.y] = board[node.x][node.y];
        }
        res[x][y] = board[x][y];
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (step != 0 && dir != i) continue;
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (target[step + 1] == board[newx][newy]) {
            path[step] = (Node) {x, y};
            dfs(newx, newy, step + 1, i);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'y') {
                dfs(i, j, 0, 0);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!judge(res[i][j])) res[i][j] = '*';
            printf("%c", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
