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
        unordered_map<int, vector<Node*>> map;
        fill(map, root, 0);
        for(auto& entry : map){
            for(int i=0; i<entry.second.size()-1; i++){
                entry.second[i]->next = entry.second[i+1];
            }
            entry.second[entry.second.size()-1]->next = NULL;
        }
        return root;
    }

    void fill(unordered_map<int, vector<Node*>>& map, Node* root, int d){
        if(!root)return;
        map[d].push_back(root);
        fill(map, root->left, d+1);
        fill(map, root->right, d+1);
    }   
};