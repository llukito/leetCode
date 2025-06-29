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
    int maxDepth(Node* root) {
        if(!root)return 0;
        int res = 0;
        check(res, root, 1);
        return res;
    }

    void check(int& res, Node* root, int depth){
        if(!root)return;
        res = max(res, depth);
        for(Node* nd : root->children){
            check(res, nd, depth+1);
        }
    }
};