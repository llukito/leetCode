class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void dfs(TreeNode* node, TreeNode* par) {
        if (!node) return;
        parent[node] = par;
        dfs(node->left, node);
        dfs(node->right, node);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, nullptr);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);
        int dist = 0;

        while (!q.empty()) {
            int size = q.size();
            if (dist == k) break;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();

                // Explore neighbors: left, right, parent
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parent[node] && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }

            dist++;
        }
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};
