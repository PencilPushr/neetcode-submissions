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

    int dfs( TreeNode* pRoot, int& iMaxHeight )
    {
        if ( pRoot == nullptr )
            return 0;

        int left = dfs( pRoot->left, iMaxHeight );
        int right = dfs( pRoot->right, iMaxHeight );

        iMaxHeight = std::max(iMaxHeight, left + right);

        return std::max( left , right ) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        int iMaxHeight = 0;

        dfs( root , iMaxHeight );

        return iMaxHeight;
    }
};