/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node *connect(Node *root) {
        if (!root) return nullptr;

        queue < Node * > que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            Node *pre = nullptr;

            while (size--) {
                Node *cur = que.front();
                que.pop();

                if (pre) pre->next = cur;
                pre = cur;

                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }
        return root;
    }
};