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

    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        // Both nullptr == same
        if ( ! p && ! q )
            return true;

        // if only one is nullptr, they are different
        if ( p == nullptr || q == nullptr )
            return false;

        // if same value -> recurse
        if ( p->val == q->val )
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        // if only one value is same -> false
        return false;
    }
};
