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
    TreeNode* converToBST(int st, int en, vector<int>& nums) {
        if(st > en) return NULL;

        int mid = (st + en) / 2;

        TreeNode* node = new TreeNode(nums[mid]);

        node->left = converToBST(st , mid - 1, nums);
        node->right = converToBST(mid + 1 , en, nums);

        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return converToBST(0, nums.size() - 1, nums);
    }
};
