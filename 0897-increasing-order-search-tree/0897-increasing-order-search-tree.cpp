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
TreeNode* head = nullptr;
TreeNode* temp = head;
    TreeNode* increasingBST(TreeNode* root) {
        check(root);
        return temp;
    }

    void check(TreeNode* root){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            if(!head){
                head = new TreeNode(root->val);
                temp = head;
            } else {
                TreeNode* addable = new TreeNode(root->val);
                head->right = addable;
                head = addable;
            }
            return;
        }
        check(root->left);
        if(!head){
            head = new TreeNode(root->val);
            temp = head;
        } else {
            TreeNode* addable = new TreeNode(root->val);
            head->right = addable;
            head = addable;
        }
        check(root->right);
    }
};