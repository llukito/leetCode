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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return fill(nums, 0, nums.size()-1);
    }

    TreeNode* fill(vector<int>& nums, int left, int right){
        if(left>right){
            return nullptr;
        }
        int index = left;
        for(int i=left+1; i<=right; i++){
            if(nums[index]<nums[i]){
                index = i;
            }
        }
        TreeNode* node = new TreeNode(nums[index]);
        node->left = fill(nums, left, index-1);
        node->right = fill(nums, index+1, right);
        return node;
    }

};