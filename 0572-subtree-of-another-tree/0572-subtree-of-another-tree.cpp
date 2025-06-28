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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot)return !root;
        if(!root)return false;
        if(root->val == subRoot->val){
            if(isSubtree(root->left, subRoot->left) && isSubtree(root->right, subRoot->right)){
                return true;
            }
        }
        if(root->left && root->left->val == subRoot->val){
            if(isSubtree(root->left->left, subRoot->left) && isSubtree(root->left->right, subRoot->right)){
                return true;
            }
        } else if(root->right && root->right->val == subRoot->val){
            if(isSubtree(root->right->left, subRoot->left) && isSubtree(root->right->right, subRoot->right)){
                return true;
            }
        }
        return false;
    }
};