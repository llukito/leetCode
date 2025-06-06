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
    int findBottomLeftValue(TreeNode* root) {
        int d = -1;
        int res = 0;
        check(root, d, res, 0);
        return res;
    }

    void check(TreeNode* root, int& d, int& result, int depth){
        if(!root)return;
        if(depth > d){
            d = depth;
            result = root->val;
        }
        check(root->left, d, result, depth+1);
        check(root->right, d, result, depth+1);
    }
};