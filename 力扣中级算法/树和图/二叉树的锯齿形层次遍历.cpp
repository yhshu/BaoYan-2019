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
    vector <vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector <vector<int>> res;
        if (!root) return res;

        queue <TreeNode *> que;
        bool left = false;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            vector<int> level;

            while (size--) {
                TreeNode *cur = que.front();
                que.pop();

                level.push_back(cur->val);

                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }

            left = !left;
            if (!left) {
                reverse(level.begin(), level.end());
            }
            res.push_back(level);
        }
        return res;
    }
};