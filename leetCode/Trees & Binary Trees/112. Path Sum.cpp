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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
         return false;
        
        bool flag = false;
        dfs(root , 0 , targetSum , flag);

        return flag;
    }

    void dfs(TreeNode* node , int sum , int targetSum , bool &flag)
    {
        sum += node->val;
        
        if(isLeaf(node))
        {
            sum == targetSum ? flag = true : 0;
            return;
        }

        if(node->left)
         dfs(node->left , sum , targetSum , flag);

        if(node->right)
         dfs(node->right , sum , targetSum , flag);
    }

    bool isLeaf(TreeNode* node)
    {
        return !node->left and !node->right;
    }
};
