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

    vector<vector<int>> BfsQueue( TreeNode* root )
    {
        std::queue<TreeNode*> q;

        if ( !root )
            return {};

        vector<vector< int >> result;

        q.push( root );
        while( !q.empty() )
        {
            vector< int > temp;
            int n = q.size(); // remember to use this, otherwise we get continuous growth and we answer 
            // level order II
            for( int i = 0; i < n; ++i )
            {
                auto cur = q.front(); q.pop();

                temp.push_back( cur->val );

                if ( cur->left ) q.push( cur->left );
                if ( cur->right ) q.push( cur->right );
            }

            result.push_back( temp );
        }

        return result;
    }

    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        constexpr bool bIsDfs = false; // false is Bfs
        
        if constexpr ( bIsDfs )
            DfsBacktrack( root, 0 );
        else
            return BfsQueue( root );

        return result;
    }
};
