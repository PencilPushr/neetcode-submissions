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
/**

propgate previous path downwards,
bring up via post order the values



*/
using llong = long long;
//  v bring back up via post order    // v Pass state down to child nodes
    bool dfs( TreeNode* root, llong min, llong max )
    {
        // Base cases: fufilled bst state
        if ( ! root )
            return true;

        // Base case 2: the node fails parent properties 
        //              either cur < (min left ancestor) OR cur > (max right ancestor)
        if ( root->val <= min || root->val >= max )
            return false;

        // post order - return values up:
        /*  post order shape has just been inlined:
            int left = dfs()
            int right = dfs()
            process left && right
            return processed value
        */
        return dfs( root->left, min, root->val ) && dfs( root->right, root->val, max );
    }

    bool isValidBST(TreeNode* root) 
    {
        return dfs( root, INT_MIN, INT_MAX );
    }
};
