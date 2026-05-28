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
    Current idea is to dfs, check if there is a right child and use that,

    So base case:
        1    // root has right child? Then only right is visible, add the right child
      /   \
    2       3

    // alternate cases:
        1    // root has right child? Then only right is visible, add the right child
      /   \
    2       3

    Alternatively we store each level, and check who is the right most node in the array ( similar to level order traversal )


    Alternative answer was the only one that seems to work mentally. I cannot think of a true recursive without a global
    that would allow us to work with this. Save for bfs, which I will attempt to solve with this.
*/

    vector< int > result;
    vector< vector< int >> levels;

    void dfs( TreeNode* root, int level )
    {
        if ( !root )
            return;

        if ( levels.size() == level )
            levels.push_back( {} ); // Could optimise this by getting rid of the push back for the level, just the last node

        printf("%d : %zu\n", level, result.size());
        levels[ level ].push_back( root->val );

        // As we go in order, the last node on each level is the rightmost node

        dfs( root->left, level + 1 );
        dfs( root->right, level + 1 );

        return;
    }

    vector< int > bfs( TreeNode* root )
    {
        if ( ! root )
            return {};

        vector< int > result;
        std::queue< TreeNode* > q;

        q.push( root );
        while( !q.empty() )
        {
            // We can skip temp construction as we recall we just need the last node of each level
            vector< int > temp;
            int n = q.size();
            for( int i = 0; i < n; ++i )
            {
                auto cur = q.front(); q.pop();

                temp.push_back( cur->val );

                if ( cur->left ) q.push( cur->left );
                if ( cur->right ) q.push( cur->right );
            }

            result.push_back( temp.back() );
        }

        return result;
    }

    vector<int> rightSideView(TreeNode* root) 
    {
        // 1. Collect all the levels
        constexpr bool isDfs = false;
        if constexpr( isDfs )
        {
            dfs( root, 0 );

            // 2. Collect last of every level
            for( int i = 0; i < levels.size(); ++i )
                result.push_back( levels[i].back() );
        }
        else
        {
            return bfs( root );
        }

        return result;    
    }
};
