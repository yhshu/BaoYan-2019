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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() != inorder.size())
            return nullptr;
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int ps, int pe, int is, int ie) {
        if (ps > pe || is > ie) return nullptr;

        TreeNode *root = new TreeNode(preorder[ps]);

        int i;
        for (i = is; i <= ie; i++) {
            if (inorder[i] == preorder[ps]) {
                break;
            }
        }

        root->left = buildTree(preorder, inorder, ps + 1, ps + i - is, is, i - 1);
        root->right = buildTree(preorder, inorder, ps + i - is + 1, pe, i + 1, ie);

        return root;
    }
};