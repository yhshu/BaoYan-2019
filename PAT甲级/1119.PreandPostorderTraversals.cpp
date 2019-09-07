//
// Created by Yiheng Shu on 2019/9/6.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int> in, pre, post;
bool unique = true;

void inOrder(int preBegin, int preEnd, int postBegin, int postEnd) {
    if (preBegin == preEnd) {  // 只有一个结点
        in.push_back(pre[preBegin]);
        return;
    }
    if (pre[preBegin] == post[postEnd]) {  // 有效情况：前序遍历的根结点 等于 后序遍历的根结点
        int preRightBegin = preBegin + 1; // 假设右子树存在
        while (preRightBegin <= preEnd && pre[preRightBegin] != post[postEnd - 1]) preRightBegin++;
        int leftLen = preRightBegin - preBegin - 1;
        if (leftLen)  // 必然存在左子树
            inOrder(preBegin + 1, preRightBegin - 1, postBegin, postBegin + leftLen - 1);
        else          // 无法判定是右子树还是左子树，因此结果不唯一
            unique = false;
        in.push_back(post[postEnd]);
        // 右子树
        inOrder(preRightBegin, preEnd, postBegin + leftLen, postEnd - 1);
    }
}

int main() {
    int nNode;
    cin >> nNode;
    pre.resize(nNode), post.resize(nNode);
    for (int i = 0; i < nNode; i++)
        cin >> pre[i];
    for (int i = 0; i < nNode; i++)
        cin >> post[i];
    inOrder(0, nNode - 1, 0, nNode - 1);
    printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
    for (int i = 1; i < in.size(); i++)
        printf(" %d", in[i]);
    printf("\n");
    return 0;
}
