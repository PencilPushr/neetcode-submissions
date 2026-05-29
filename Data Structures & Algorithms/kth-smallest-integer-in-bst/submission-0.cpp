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
/*

    1.    either use an array/stack and build up the array until finished, then iterate through until k
    or
    2.    iterate 2 times, first time to get the size of the bst, second time to decrement until 0 + k
        size s of tree -> s - k = diff ?
    or 
    3.    maybe there is a backtracking solution? pass down k by value, add to it until it matches global k -> this is the value?

*/
    int g_iResult = -1;
    int g_iCounter = 0;

    void dfs( TreeNode* root, int k )
    {
        if ( ! root )
            return;

        if( g_iCounter >= k )
            return;

        // in order due to bst property
        dfs( root->left, k );

        ++g_iCounter;
        if ( g_iCounter == k)
        {
            g_iResult = root->val;
            return;
        }

        dfs( root->right, k );
    }

    int kthSmallest(TreeNode* root, int k) 
    {
        dfs( root, k );
        return g_iResult;
    }
};
