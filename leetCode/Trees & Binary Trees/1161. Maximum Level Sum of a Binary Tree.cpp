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
    int BFS(TreeNode* root) {
        int ans = 0, mxSum = INT_MIN, size = 1, level = 1;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int sum = 0;

            for(int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left)
                 q.push(node->left);

                if(node->right)
                 q.push(node->right);
            }

            if(sum > mxSum) {
                mxSum = sum;
                ans = level;
            }
            
            level++;
            size = q.size();
        }

        return ans;
    }
public:
    int maxLevelSum(TreeNode* root) {
        return BFS(root);
    }
};
