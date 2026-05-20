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

    TreeNode* invertTree(TreeNode* root) 
    {
        if (!root) return nullptr;

        std::queue<TreeNode*> q;

        q.push(root);
        while(!q.empty())
        {
            TreeNode* curNode = q.front(); q.pop();

            TreeNode* temp = curNode->left;
            curNode->left = curNode->right;
            curNode->right = temp;

            if (curNode->left != nullptr) q.push(curNode->left);
            if (curNode->right != nullptr) q.push(curNode->right);
        }
        return root;
    }
};
