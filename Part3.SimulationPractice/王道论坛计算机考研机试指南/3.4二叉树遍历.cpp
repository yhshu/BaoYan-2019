/*
样例输入：
ABC
BAC
FDXEAG
XDEFAG

样例输出：
BCA
XEDGAF
*/

#include <cstring>
#include <iostream>
using namespace std;

struct Node {
  Node *left;
  Node *right;
  char c;
} Tree[50];

int loc; // 静态数组中已分配的结点个数

Node *create() { // 申请一个结点空间，返回指向其的指针
  Tree[loc].left = Tree[loc].right = NULL;
  return &Tree[loc++];
}

char str1[30], str2[30]; // 保存前序和中序遍历结果字符串

void postOrder(Node *T) // 后序遍历
{
  if (T->left != NULL) {
    postOrder(T->left);
  }
  if (T->right != NULL) {
    postOrder(T->right);
  }
  cout << T->c;
}

Node *build(int s1, int e1, int s2, int e2) {
  // 由字符串的前序遍历和中序遍历还原树，并返回其根节点
  // 前序遍历结果为 str1[s1] 到 str2[e1]，中序遍历结果为 str2[s2] 到 str2[e2]
  Node *ret = create(); // 为根结点申请空间
  ret->c = str1[s1];
  int rootIdx;                     // str2 中的根结点索引
  for (int i = s2; i <= e2; i++) { // 查找该根结点字符在中序遍历中的位置
    if (str2[i] == str1[s1]) {
      rootIdx = i;
      break;
    }
  }

  if (rootIdx != s2) { // 若左子树不为空
    ret->left = build(s1 + 1, s1 + (rootIdx - s2), s2, rootIdx - 1);
    // 递归还原其左子树
  }

  if (rootIdx != e2) { // 若右子树不为空
    ret->right = build(s1 + (rootIdx - s2) + 1, e1, rootIdx + 1, e2);
    // 递归还原其右子树
  }
  return ret;
}

int main() {
  while (cin >> str1) {
    cin >> str2;
    loc = 0;
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    Node *T = build(0, l1 - 1, 0, l2 - 1);
    postOrder(T);
    cout << endl;
  }
  return 0;
}
