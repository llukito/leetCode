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
    int longestZigZag(TreeNode* root) {
        int res = 0;
        check(res, root);
        return res-1;
    }

    void check(int& res, TreeNode* root){
        if(!root)return;
        test(root, res, 0, -1);
        test(root, res, 0, 1);
        check(res, root->left);
        check(res, root->right);
    }

    void test(TreeNode* root, int& res, int curr, int dir){
        if(!root){
            res = max(res, curr);
            return;
        }
        curr+=1;
        if(dir == -1){
            test(root->right, res, curr, 1);
        } else if(dir == 1){
            test(root->left, res, curr, -1);
        }
    }
};