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
    int getMinimumDifference(TreeNode* root) {
        int result = INT_MAX;
        fill(result, root);
        return result;
    }

    void fill(int& result, TreeNode* root){
        if(!root)return;
        if(root->left){
            result = min(result, abs(root->val - root->left->val));
        }
        if(root->right){
            result = min(result, abs(root->val -root->right->val));
        }
        fill(result, root->left);
        fill(result, root->right);
    }
};