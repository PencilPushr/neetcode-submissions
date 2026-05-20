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

    int m_iDepth = 0;

    void dfs( TreeNode* root , int depth )
    {
        if ( root == nullptr )
            return;

        dfs( root->left , depth + 1 );

        m_iDepth = std::max( m_iDepth , depth );

        dfs ( root->right , depth + 1 );

        return;
    }

    int maxDepth(TreeNode* root) 
    {
        int depth = 1;
        dfs( root , depth );
        return m_iDepth;
    }
};
