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

// space-complexity => O(1)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool check = true;
        testBST(root , check);
        return check;
    }

    pair<int,int> testBST(TreeNode* node , bool &check)
    {   
        if(!node) return make_pair(INT_MAX , INT_MIN);
        pair<int,int> left , right;

        left = testBST(node->left , check);
        right = testBST(node->right , check);

        if(node->left and left.second >= node->val)
         check = false;

        if(node->right and right.first <= node->val)
         check = false;

        int mn = min(node->val , left.first);
        int mx = max(node->val , right.second);

        return make_pair(mn , mx);
    }
};



/*
  space-complexity => O(n) 

  Idea => Inorder Traversal of Valid BST is always strictly increasing array
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        InOrder(root , v);

        for(int i = 1 ; i < v.size() ; ++i)
         if(v[i] <= v[i-1])
          return false;
        
        return true;
    }

    void InOrder(TreeNode* node , vector<int> &v)
    {   
        if(!node) return;

        InOrder(node->left , v);
        v.push_back(node->val);
        InOrder(node->right , v);
    }
};
