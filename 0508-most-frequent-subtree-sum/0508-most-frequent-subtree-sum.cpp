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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> mp;
        int freq = 0;
        fill(mp, root, freq);
        vector<int> res;
        for(auto& entry : mp){
            if(entry.second == freq){
                res.push_back(entry.first);
            }
        }
        return res;
    }

    void fill(map<int, int>& mp,TreeNode* root, int& freq){
        if(!root)return;
        int s = sum(root);
        mp[s]++;
        freq = max(freq, mp[s]);
        fill(mp, root->left, freq);
        fill(mp, root->right, freq);
    }

    int sum(TreeNode* root){
        if(!root)return 0;
        return root->val + sum(root->left)+sum(root->right);
    }
};