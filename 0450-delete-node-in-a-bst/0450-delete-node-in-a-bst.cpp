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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if(root->val == key){
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            } else if(root->left && !root->right){
                TreeNode* nd = root->left;
                delete root;
                 return nd;
            } else if(root->right && !root->left){
                TreeNode* nd = root->right;
                delete root;
                 return nd;
            } else {
               TreeNode* successor = getNode(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
                return root;
            }
        } else if(root->val > key){
             root->left = deleteNode(root->left, key);
        }
        root->right = deleteNode(root->right, key);
        return root;
    }

    TreeNode* getNode(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }
};