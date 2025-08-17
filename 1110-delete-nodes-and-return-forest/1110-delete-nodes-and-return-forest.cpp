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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> vect;
        fill(vect, root);
        unordered_set<int> set(to_delete.begin(), to_delete.end());
        check(root, set);
        unordered_set<TreeNode*> visited;
        vector<TreeNode*> res;
        for(TreeNode* nd : vect){
            if(nd && !set.count(nd->val) && !visited.count(nd)){
                res.push_back(nd);
                refill(visited, nd);
            }
        }
        return res;
    }

    void refill(unordered_set<TreeNode*>& visited, TreeNode* nd){
        if(!nd)return;
        visited.insert(nd);
        refill(visited, nd->left);
        refill(visited, nd->right);
    }

    void fill(vector<TreeNode*>& vect, TreeNode* root){
        if(!root)return;
        vect.push_back(root);
        fill(vect, root->left);
        fill(vect, root->right);
    }

    void check(TreeNode*& root, unordered_set<int>& set){
        if(!root)return;
        TreeNode*& l = root->left; 
        TreeNode*& r = root->right;
        if(set.count(root->val)){
            root = nullptr;
        }
        check(l, set);
        check(r, set); 
    }
};