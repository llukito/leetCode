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
    int diameterOfBinaryTree(TreeNode* root) {
        int result =0;
        check(root, result);
        return result;
    }

    int check(TreeNode* root, int& result){
        if(!root)return 0;
        int l = check(root->left, result);
        int r = check(root->right, result);
        result = max(result, l+r);
        return max(l,r)+1;
    }
};