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

    int g_maxDepth;

    void dfs(TreeNode* cur, int result)
    {
        if (cur == nullptr) return;

        dfs(cur->left, result + 1);

        g_maxDepth = std::max(g_maxDepth, result);

        dfs(cur->right, result + 1);
    }

    int maxDepth(TreeNode* root) 
    {
        g_maxDepth = 0;
        int result = 1;
        dfs(root, result);
        return g_maxDepth;
    }
};
