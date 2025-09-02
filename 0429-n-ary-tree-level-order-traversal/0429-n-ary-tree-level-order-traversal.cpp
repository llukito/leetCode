/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        map<int, vector<int>> m;
        fill(root, m, 0);
        vector<vector<int>> res;
        for(auto& entry : m){
            res.push_back(entry.second);
        }
        return res;
    }

    void fill(Node* root, map<int, vector<int>>& m, int d){
        if(!root)return;
        m[d].push_back(root->val);
        for(Node* nd : root->children){
            fill(nd, m, d+1);
        }
    }
};