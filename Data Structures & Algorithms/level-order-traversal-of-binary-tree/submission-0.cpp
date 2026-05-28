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



*/

    vector<vector<int>> result;

    void DfsBacktrack( TreeNode* root, int level )
    {
        if ( ! root )
            return;

        // Push a new empty bucket for the level - this works because:
        // At level 0 there are 0 other extra buckets (we default init: { {} } )
        // At level 1 there is 1 extra bucket ( { {root}, {} } ) ...
        if ( result.size() == level )
            result.push_back({});

        result[ level ].push_back( root->val );

        DfsBacktrack( root->left, level +1 );
        DfsBacktrack( root->right, level +1 );
    }

    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        DfsBacktrack( root, 0 );
        return result;
    }
};
