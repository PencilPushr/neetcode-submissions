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

class Solution 
{
public:
    int g_maxHeight = 0;

    int dfs(TreeNode* cur)
    {
        if (cur == nullptr) return 0;

        int left = dfs(cur->left);
        int right = dfs(cur->right);

        // Update diameter: longest path through this node
        g_maxHeight = std::max(g_maxHeight, left + right);
        
        // Return height of this subtree
        return 1 + std::max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {       
        dfs(root);
        return g_maxHeight;
    }
};
