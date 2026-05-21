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

    // iterate through tree - if we get through entire tree without matching subroot - no match

*/

    bool isSameTree( TreeNode* p, TreeNode* q)
    {
        if ( !p && !q ) return true;
        if ( !p || !q ) return false;
        if ( p->val != q->val ) return false;
        return isSameTree( p->left , q->left ) && isSameTree( p->right, q->right );
    }

    bool dfs( TreeNode* root, TreeNode* subroot )
    {
        // Reached the end of the tree - but not the end of the subtree
        if ( ! root )
            return false;

        // Check if the current node is the same tree
        if ( isSameTree( root, subroot ) )
            return true;

        return dfs( root->left, subroot ) || dfs( root->right, subroot );
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) 
    {
        if ( !root && !subroot ) return true;
        return dfs(root, subroot);
    }
};
