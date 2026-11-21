class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }
        vector<int> lastSeen(26, -1);
        vector<int> answer(n, 1);
        dfs(0, parent, s, children, lastSeen, answer);
        return answer;
    }
    
    void dfs(int node, vector<int>& parent, string& s, vector<vector<int>>& children, vector<int>& lastSeen, vector<int>& answer) {
        int c = s[node] - 'a';
        int saved = lastSeen[c];
        int newParent = parent[node];
        if (saved != -1) {
            newParent = saved;
        }

        lastSeen[c] = node;
        for (int child : children[node]) {
            dfs(child, parent, s, children, lastSeen, answer);
        }
        lastSeen[c] = saved;

        if (newParent != -1) {
            answer[newParent] += answer[node];
        }
    }
};