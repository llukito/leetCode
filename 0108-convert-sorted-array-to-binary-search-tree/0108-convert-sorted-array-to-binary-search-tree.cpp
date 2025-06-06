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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int rootValue = nums[nums.size()/2];
        TreeNode* root = new TreeNode(rootValue);
        root->left = root->right = nullptr;
        for(int i=0; i<nums.size(); i++){
            if(i == nums.size()/2)continue;
            TreeNode*& ndd = findNode(root, nums[i]);
            ndd = new TreeNode(nums[i]);
            ndd->left = ndd->right = nullptr;
        }
        return root;
    }

    TreeNode*& findNode(TreeNode*& root, int n){
        if(!root)return root;
        if(root->val < n){
            return findNode(root->right, n);
        } else if(root->val >n){
            return findNode(root->left, n);
        }
        return root;
    }
};