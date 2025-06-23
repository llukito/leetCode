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
    TreeNode* pruneTree(TreeNode* root) {
        check(root);
        return root;
    }

    void check(TreeNode*& root){
        if(!root)return;
        if(!valid(root)){
            // delete root;
            root = nullptr;
        } else{
            check(root->left);
            check(root->right);
        }
    }

    bool valid(TreeNode* root){
        if(!root)return false;
        if(root->val == 1)return true;
        if(valid(root->left))return true;
        if(valid(root->right))return true;
        return false;
    }
};