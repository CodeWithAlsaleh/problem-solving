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
    unordered_map<TreeNode* , TreeNode*> mp; // [child , parent]
    int deepestLeaves = 0;

    void buildMap(TreeNode* node, TreeNode* parent, int depth) {
        if(node == NULL) return;

        deepestLeaves = max(deepestLeaves , depth);

        if(parent)
         mp[node] = parent;

        buildMap(node->left , node , depth + 1);
        buildMap(node->right , node , depth + 1);
    }

    vector<TreeNode*> getDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> ans;

        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root , 0));

        while(!q.empty()) {
            /*
                Don't use here [auto &p] cuz if u remove it [q.pop()]
                after some time it will be erased from the memory so
                in some cases u won't be able to access it here [p.second == deepestLeaves]
            */
            auto p = q.front();
            q.pop();

            if(p.second == deepestLeaves)
             ans.push_back(p.first);

            if(p.first->left)
             q.push(make_pair(p.first->left , p.second + 1));

            if(p.first->right)
             q.push(make_pair(p.first->right , p.second + 1));
        }

        return ans;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        buildMap(root , NULL , 0);
        vector<TreeNode*> check = getDeepestLeaves(root);

        if(check.size() == 1)
         return check[0];

        bool flag = false;

        while(!flag) {
            flag = true;
            TreeNode* checkNode = check[0];

            for(auto &it : check) {
                if(mp[checkNode] != mp[it]) {
                    flag = false;
                    break;
                }
            }

            if(flag)
             return mp[checkNode];

            for(int i = 0 ; i < check.size() ; ++i)
             check[i] = mp[check[i]];
        }

        return root;
    }
};
