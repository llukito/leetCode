/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        map<int, vector<Node*>> mp;
        fill(mp, 0, root);
        for(auto& entry : mp){
            for(int i=0; i<entry.second.size()-1; i++){
                entry.second[i]->next = entry.second[i+1];
            }
            entry.second[entry.second.size()-1]->next = nullptr;
        }
        return root;
    }

    void fill(map<int, vector<Node*>>& mp, int depth, Node* root){
        if(!root)return;
        mp[depth].push_back(root);
        fill(mp, depth+1, root->left);
        fill(mp, depth+1, root->right);
    }
};