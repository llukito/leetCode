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
    int sumNumbers(TreeNode* root) {
        int total = 0;
        calcSum(root, "", total);
        return total;
    }

    void calcSum(TreeNode*& root, string curr, int& total){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            curr+=to_string(root->val);
            total+=stoi(curr);
            return;
        }
        curr+=to_string(root->val);
        calcSum(root->left, curr, total);
        calcSum(root->right, curr, total);
    }
};