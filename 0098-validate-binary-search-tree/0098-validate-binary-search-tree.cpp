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
    bool isValidBST(TreeNode* root) {
        return check(root);
    }

    bool check(TreeNode* root){
        if(!root){
            return true;
        }
        if(!lower(root->left, root->val)){
            return false;
        }
        if(!higher(root->right, root->val)){
            return false;
        }
        return check(root->left) && check(root->right);
    }

    bool lower(TreeNode* root, int i){
        if(!root){
            return true;
        }
        if(root->val >= i){
            return false;
        }
        return lower(root->left, i) && lower(root->right, i);
    }

    bool higher(TreeNode* root, int i){
        if(!root){
            return true;
        }
        if(root->val <= i){
            return false;
        }
        return higher(root->left, i) && higher(root->right, i);
    }
};