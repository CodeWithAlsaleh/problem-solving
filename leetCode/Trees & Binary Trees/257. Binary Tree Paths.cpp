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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        queue<pair<TreeNode*, string>> q;

        q.push(make_pair(root, to_string(root->val)));

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            bool flag = false;
            if(p.first->left) {
                flag = true;

                q.push(make_pair(p.first->left, p.second + "->" + to_string(p.first->left->val)));
            }

            if(p.first->right) {
                flag = true;

                q.push(make_pair(p.first->right, p.second + "->" + to_string(p.first->right->val)));
            }

            if(!flag)
             ans.push_back(p.second);
        }

        return ans;
    }
};
