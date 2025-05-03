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
    vector<int> findMode(TreeNode* root) {
       map<int,int> mp; 
       f(mp, root);
       int max_ = 0; 
       for(auto& entry : mp){
            max_ = max(max_, entry.second);
       }
       vector<int> vect;
       for(auto& entry : mp){
            if(entry.second == max_){
                vect.push_back(entry.first);
            }
       }
       return vect;
    }

    void f(map<int,int>& mp, TreeNode* root){
        if(!root)return;
        mp[root->val]++;
        f(mp, root->left);
        f(mp, root->right);
    }
};