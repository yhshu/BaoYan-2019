//
// Created by Yiheng Shu on 2019/9/5.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int nCases, nQueens;
bool firstline = true;

void nextline() {
    if (firstline) firstline = false;
    else printf("\n");
}

bool judge(const vector<int> &board) {
    const int size = board.size();
    // 判断是否有皇后在同一行、同一对角线、同一副对角线上
    // 题目设置已经简化， 不会有皇后出现在同一列上
    set<int> rowSet;
    set<int> diagSet;
    set<int> counterDiagSet;

    for (int col = 1; col <= size; col++) {
        int row = board[col - 1];
        rowSet.insert(row);
        diagSet.insert(row - col);
        counterDiagSet.insert(row + col);
    }
    return rowSet.size() == size && diagSet.size() == size && counterDiagSet.size() == size;
}

int main() {
    cin >> nCases;
    vector<int> board;
    for (int i = 0; i < nCases; i++) {
        board.clear();

        cin >> nQueens;
        for (int j = 0; j < nQueens; j++) {
            int queen;
            cin >> queen;

            board.push_back(queen);
        }

        nextline();

        if (judge(board)) printf("YES");
        else printf("NO");
    }
    return 0;
}