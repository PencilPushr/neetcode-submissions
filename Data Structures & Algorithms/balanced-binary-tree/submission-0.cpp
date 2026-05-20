/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool m_isBalanced;

    int dfs(TreeNode* cur)
    {
        if (cur == nullptr) return 0;

        int l = dfs(cur->left);
        int r = dfs(cur->right);

        if (std::abs(l - r) > 1) m_isBalanced = false;

        return 1 + std::max(l, r);
    }

    bool isBalanced(TreeNode* root) 
    {
        m_isBalanced = true;
        dfs(root);
        return m_isBalanced;
    }
};
