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
    Looking at this problem, this seems very easily solved by doing some sort of bfs or level order traversal

    However I want to approach it in the dfs or recursive manner
    Going over this I think we can appropriate level order traversal strategy/zigzag 
        - but now we just need to iterate instead of pushing to a vector 
    Use post order traversal so we can collect the children and swap

    1. recurse using post order dfs and collect children
    2. create temp (or use std::swap() ) and swap the nodes, return back up
*/

    /*
    TreeNode* dfs( TreeNode* root )
    {
        // Nothing to swap go back up
        if ( !root )
            return nullptr;

        // Collect children
        TreeNode* pLeft = dfs( root->left );
        TreeNode* pRight = dfs( root->right );

        // Swap
        std::swap( pLeft, pRight);

        return root;
    }
    */

    void dfs( TreeNode* root )
    {
        if ( !root )
            return;

        dfs( root->left );
        dfs( root->right );

        std::swap( root->left, root->right );

        return;
    }

    TreeNode* invertTree(TreeNode* root) 
    {
        // This is actually insanely useful, it helps in other problems
        if ( !root )
            return nullptr;

        //return dfs( root );
        dfs( root );

        return root;
    }
};
