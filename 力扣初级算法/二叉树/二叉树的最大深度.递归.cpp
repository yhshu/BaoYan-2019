// 递归过程中考虑的情况

// 1. 空结点
// 2. 叶结点
// 3. 中间结点或根结点

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        if (!root->left && !root->right)
            return 1;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};