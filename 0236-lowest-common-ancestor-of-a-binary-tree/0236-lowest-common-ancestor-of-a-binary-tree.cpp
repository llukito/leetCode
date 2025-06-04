/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)return root;
        bool b1 = there(root->left, p) && there(root->left, q);
        bool b2 = there(root->right, p) && there(root->right, q);
        if (!b1 && !b2)return root;
        if (b1) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return lowestCommonAncestor(root->right, p, q);
    }

    bool there(TreeNode* root, TreeNode* temp){
        if(!root)return false;
        if(root == temp)return true;
        return there(root->left, temp) || there(root->right, temp);
    }
};