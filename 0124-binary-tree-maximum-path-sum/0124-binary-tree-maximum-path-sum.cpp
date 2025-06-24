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
    int maxPathSum(TreeNode* root) {
        if(!root->left && !root->right)return root->val;
        int result = INT_MIN;
        check(result, root);
        return result;
    }

    int check(int& result, TreeNode* root){
        if(!root)return 0;
        result = max(result, root->val);
        int left = check(result, root->left);
        int right = check(result, root->right);
        if(left>0 && right>0){
            result = max(result, left+right+root->val);
        }
        if(root->val > 0){
            result = max(result, left+root->val);
            result = max(result, right+root->val); 
        }
        return max(left, right)+root->val;
    }
};