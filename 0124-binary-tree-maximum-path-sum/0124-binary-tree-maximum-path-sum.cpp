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
        int result = INT_MIN;
        check(root, result);
        return result;
    }

    int check(TreeNode* root, int& result){
        if(!root)return 0;
        int l = max(check(root->left, result), 0);
        int r  = max(check(root->right, result), 0);
        result = max(result, l+r+root->val);
        return root->val +max(l,r);
    }
};