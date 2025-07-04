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
    int longestUnivaluePath(TreeNode* root) {
        if(!root)return 0;
        int res = 0;
        check(root, res, root->val);
        return res;
    }

    int check(TreeNode* root, int& res, int val){
        if(!root){
            return 0;
        }
        int left = 0; int right = 0;
        if(root->left){
            left = check(root->left, res, root->left->val);
        }
        if(root->right){
            right = check(root->right, res, root->right->val);
        }
        int curr = 0;
        int temp1 =0; int temp2 = 0;
        if(root->left && root->left->val == val){
            curr+=left+1;
            temp1 = left+1;
        }
         if(root->right && root->right->val == val){
            curr+=right+1;
            temp2 = right+1;
        }
        res = max(res, curr);
        return max(temp1, temp2);
    }
};