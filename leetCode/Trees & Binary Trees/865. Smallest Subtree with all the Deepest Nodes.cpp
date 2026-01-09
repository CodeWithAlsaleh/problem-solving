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
    int getMaxDepth(TreeNode* node, int depth) {
        int left = depth, right = depth;

        if(node->left)
         left = getMaxDepth(node->left, depth + 1);

        if(node->right)
         right = getMaxDepth(node->right, depth + 1);

        return max(left, right);
    }

    void getNodesAtMaxDepth(TreeNode* node, TreeNode* parent, vector<TreeNode*> &maxDepthNodes, unordered_map<TreeNode*, TreeNode*> &getParent, int curDepth, int &maxDepth) {
        if(curDepth == maxDepth) {
         getParent[node] = parent;
         maxDepthNodes.push_back(node);
         return;
        }

        if(node->left)
            getNodesAtMaxDepth(node->left, node, maxDepthNodes, getParent, curDepth + 1, maxDepth);

        if(node->right)
            getNodesAtMaxDepth(node->right, node, maxDepthNodes, getParent, curDepth + 1, maxDepth);

        getParent[node] = parent;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> getParent;
        int maxDepth = getMaxDepth(root, 0);

        vector<TreeNode*> maxDepthNodes;
        getNodesAtMaxDepth(root, NULL, maxDepthNodes, getParent, 0, maxDepth);

        while(true) {
            bool flag = true;

            TreeNode* curNode = maxDepthNodes[0];

            for(auto &it : maxDepthNodes) 
             if(it != curNode)
              flag = false;

            if(flag) return curNode;

            for(int i = 0; i < maxDepthNodes.size(); ++i)
             maxDepthNodes[i] = getParent[maxDepthNodes[i]];
        }

        return NULL;
    }
};
