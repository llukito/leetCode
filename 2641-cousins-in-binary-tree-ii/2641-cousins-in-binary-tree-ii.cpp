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
    vector<int> vect;
    int idx = 0;

    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, vector<pair<TreeNode*, TreeNode*>>> map;
        fill(root, nullptr, map, 0);
        check(root, nullptr, map, 0);
        final(root);
        return root;
    }

    
    void fill(TreeNode* root, TreeNode* parent, auto& map, int depth){
        if(!root)return;
        map[depth].push_back({parent, root});
        fill(root->left, root, map, depth+1);
        fill(root->right, root, map, depth+1);
    }

    void check(TreeNode* root, TreeNode* parent, auto& map, int depth){
        if(!root)return;
        int num = 0;
        for(auto& entry : map[depth]){
            if(entry.first != parent){
                num+=entry.second->val;
            }
        }
        vect.push_back(num);
        check(root->left, root, map, depth+1);
        check(root->right, root, map, depth+1);
    }

    void final(TreeNode* root){
        if(!root)return;
        root->val = vect[idx++];
        final(root->left);
        final(root->right);
    }
};