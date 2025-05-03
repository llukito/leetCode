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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        get(root, sum, false);
        return sum;
    }

    void get(TreeNode* root, int& sum, bool b){
        if(!root)return;
        if(!root->left && !root->right && b){
            sum+=root->val;
        }
        get(root->left, sum, true);
        get(root->right, sum, false);
    }
};