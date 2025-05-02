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
    bool isBalanced(TreeNode* root) {
        return check(root);
    }

    bool check(TreeNode* root){
        if(!root)return true;
        int leftDepth = dpth(root->left);
        int rightDepth = dpth(root->right);
        if(abs(leftDepth-rightDepth)>1)return false;
        return check(root->left) && check(root->right);
    }

    int dpth(TreeNode* root){
        int level = 0;
        calculate(root,0, level);
        return level;
    }

    void calculate(TreeNode* root, int curr, int& level){
        if(!root){
            level = max(level, curr);
            return;
        }
        calculate(root->left, curr+1, level);
        calculate(root->right, curr+1, level);
    }
};