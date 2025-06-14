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
    int goodNodes(TreeNode* root) {
        int num = 0;
        check(root, num, root->val);
        return num;
    }

    void check(TreeNode* root, int& num, int edge){
        if(!root)return;
        if(root->val >= edge){
            num++;
        }
        check(root->left, num, max(edge, root->val));
        check(root->right, num, max(edge, root->val));
    }
};