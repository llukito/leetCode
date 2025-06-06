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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* nd = check(root, val);
        return nd;
    }

    TreeNode* check(TreeNode*& root, int& val){
        if(!root){
            return nullptr;
        }
        if(root->val == val){
            return root;
        } 
        TreeNode* n1 = check(root->left, val);
        if(n1!=nullptr)return n1;
        return check(root->right, val);
    }
};