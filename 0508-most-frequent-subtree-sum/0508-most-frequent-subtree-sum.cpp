class Solution {
public:
    int dfs(TreeNode* root, vector<int>& v) {
        if (root == nullptr) return 0;
        int sum = root->val + dfs(root->left, v) + dfs(root->right, v);
        v.push_back(sum);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> v;
        if (!root) return v;
        dfs(root, v);
        map<int,int> mp;
        for (int i=0;i<v.size();i++) mp[v[i]]++;
        int cnt = 0;
        for (int i=0;i<v.size();i++) cnt = max(cnt, mp[v[i]]);
        set<int> res;
        for (int i=0;i<v.size();i++){
            if (mp[v[i]] == cnt) res.insert(v[i]);
        }
        vector<int> ans;
        for (int x : res) ans.push_back(x);
        return ans;
    }
};