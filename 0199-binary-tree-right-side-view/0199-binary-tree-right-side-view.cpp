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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vect;
        map<int, int> mp;
        check(mp, root, 0);
        for(auto& entry : mp){
            vect.push_back(entry.second);
        }
        return vect;
    }

    void check(map<int, int>& mp, TreeNode* root, int depth){
        if(!root)return;
        mp[depth] = root->val;
        check(mp, root->left, depth+1);
        check(mp, root->right, depth+1);
    }
};