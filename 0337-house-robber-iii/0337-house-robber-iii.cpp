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
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int rob = root->val + left.second + right.second;

        int notRob = max(left.first, left.second) + max(right.first, right.second);

        return {rob, notRob};
    }

    int rob(TreeNode* root) {
        auto result = dfs(root);
        return max(result.first, result.second);
    }
};
