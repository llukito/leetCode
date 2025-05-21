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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        fill(graph, root);
        int res = 0;
        unordered_set<int> set;
        check(graph, 0, res, start, set);
        return res;
    }

    void check(unordered_map<int, vector<int>>& graph, int depth, int& res, int start, unordered_set<int>& set){
        res = max(res, depth);
        for(int n : graph[start]){
            if(!set.count(n)){
                set.insert(start);
                check(graph, depth+1, res, n, set);
                set.erase(start);
            }
        }
    }

    void fill(unordered_map<int, vector<int>>& graph, TreeNode* root){
        if(!root)return;
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            fill(graph, root->left);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            fill(graph, root->right);
        }
    }

};