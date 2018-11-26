#include <iostream>
#define MAXN 110
using namespace std;

struct Node {
  Node *left;
  Node *right;
  int c;
} Tree[MAXN];

int loc;

Node *create() {
  Tree[loc].left = Tree[loc].right = NULL;
  return &Tree[loc++];
}

void postOrder(Node *T) { // 后序遍历
  if (T->left != NULL) {
    postOrder(T->left);
  }
  if (T->right != NULL) {
    postOrder(T->right);
  }
  cout << T->c << " ";
}

void inOrder(Node *T) { // 中序遍历
  if (T->left != NULL)
    inOrder(T->left);
  cout << T->c << " ";
  if (T->right != NULL)
    inOrder(T->right);
}

void preOrder(Node *T) { // 前序遍历
  cout << T->c << " ";
  if (T->left != NULL) {
    preOrder(T->left);
  }
  if (T->right != NULL) {
    preOrder(T->right);
  }
}

Node *insert(Node *T, int x) {
  if (T == NULL) {
    T = create();
    T->c = x;
    return T;
  } else if (x < T->c)
    T->left = insert(T->left, x);
  else if (x > T->c)
    T->right = insert(T->right, x);
  return T;
}

int main() {
  int n;
  while (cin >> n) {
    loc = 0;
    Node *T = NULL; // 二叉排序树树根结点为空
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      T = insert(T, x);
    }
    preOrder(T);
    cout << endl;
    inOrder(T);
    cout << endl;
    postOrder(T);
    cout << endl;
  }
  return 0;
}
