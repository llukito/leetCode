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
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        check(root, k, res);
        return res;
    }

    void check(TreeNode* root, int& k, int& res){
        if(res != -1)return;
        if(!root)return;
        if(k==0){
            res = root->val;
            return;
        }
        check(root->left, k, res);
        k--;
        if(k==0){
            res = root->val;
            return;
        }
        check(root->right, k, res);
    }
};