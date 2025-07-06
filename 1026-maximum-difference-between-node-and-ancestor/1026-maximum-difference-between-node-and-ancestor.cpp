class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }

    int dfs(TreeNode* node, int curMin, int curMax) {
        if (!node) return curMax - curMin;
        curMin = min(curMin, node->val);
        curMax = max(curMax, node->val);
        int left = dfs(node->left, curMin, curMax);
        int right = dfs(node->right, curMin, curMax);
        return max(left, right);
    }
};
