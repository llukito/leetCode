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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        helper(root, val);
        return root;
    }

    void helper(TreeNode*& root, int val){
        if(!root){
            root = new TreeNode(val);
            return;
        }
        if(root->val > val){
            helper(root->left, val);
        } else {
            helper(root->right, val);
        }
    }
};