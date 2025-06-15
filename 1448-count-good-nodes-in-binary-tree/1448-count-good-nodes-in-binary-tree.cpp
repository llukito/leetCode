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
    void check(int& res, TreeNode* root, int maxValue) {
        if (!root)return;
        if (root->val >= maxValue) {
            res++;
            maxValue = root->val;
        }
        check(res, root->left, maxValue);
        check(res, root->right, maxValue);
    }

    int goodNodes(TreeNode* root) {
        int res = 0;
        check(res, root, INT_MIN);
        return res;
    }
};