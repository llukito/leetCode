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
    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        check(root, targetSum, 0, res, true);
        return res;
    }

    void check(TreeNode* root, int targetSum, long long curr, int& res, bool b){
        if(!root)return;
        if(curr + root->val == targetSum){
            cout<<root->val<<endl;
            res++;
        }
        check(root->left, targetSum, curr+root->val, res, b);
        check(root->right, targetSum, curr+root->val, res, b);
        if(b){
            check(root->left, targetSum, 0, res, false);
            check(root->right, targetSum, 0, res, false);
        }
    }
};