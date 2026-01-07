class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> subsums;

    long long dfs(TreeNode* node) {
        if (!node) return 0;
        long long left = dfs(node->left);
        long long right = dfs(node->right);
        long long s = left + right + node->val;
        subsums.push_back(s);
        return s;
    }

    int maxProduct(TreeNode* root) {
        long long totalSum = dfs(root);
        long long ans = 0;
        for (long long s : subsums) {
            ans = max(ans, s * (totalSum - s));
        }
        return ans % MOD;
    }
};
