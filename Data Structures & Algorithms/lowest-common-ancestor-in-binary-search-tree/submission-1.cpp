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
/*

    Recurse pre order?

    1. Collect nodes then check if cur node, or left and right such that they match p and q

    2. Pre order? Or maybe check that left > cur->left -> go left until not true, then check if cur->right = right?
*/
    TreeNode* dfs( TreeNode* root, TreeNode* p, TreeNode* q )
    {
        // Base case
        if ( !root || !p || !q )
            return nullptr;

        // Answer 2 but not preorder - we check which way to go O(h) not O(n) 
        // we need to check which way to go

        // if left is smaller and right is maller, we go left
        if ( p->val < root->val && q->val < root->val )
            return dfs( root->left, p, q );

        // Otherwise if left is bigger and right is bigger go right
        if ( p->val > root->val && q->val > root->val )
            return dfs( root->right, p, q );


        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return dfs( root, p, q );
    }
};
