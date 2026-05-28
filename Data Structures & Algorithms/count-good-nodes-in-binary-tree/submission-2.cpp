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

First idea is to iterate and keep a track of the accumulated value for the current path
DFS with an accumulated value by copy allows at each path whether or not it is greater than curr node

                1
               2  -1
             3  4

            1 -> 2 // Fine, 1 < 2 -> dfs( root->left, previousAccumVal + cur->val)
            1 -> -1 // False, 1 > -1
            1 -> 2 -> 3 // true 1+2 == 3 which is <= 3
            1 -> 2 -> 4 // true 3 <= 4

            say there was 5 after 4? 1 + 2 + 4 = 6, 5 < 6? reject
             1
            2
          3   4
            5  ? 
*/
    vector< int > nodes;

    /*
            3
          3   null
        4   2
    */

    void dfs( TreeNode* root, int previousMax )
    {
        if ( ! root )
            return;

        // The above path is 
        if ( previousMax <= root->val )
            nodes.push_back( root->val );

        int maxSoFar = max( previousMax, root->val );

        dfs( root->left, maxSoFar );
        dfs( root->right, maxSoFar );
    }

    int goodNodes(TreeNode* root) 
    {
        dfs( root, INT_MIN );
        for( auto& i : nodes )
            printf("%d", i);
        return nodes.size();
    }
};
