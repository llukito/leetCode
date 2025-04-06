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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> vec;
        fillIt(result, root, vec, targetSum, 0);
        return result;
    }

    void fillIt(vector<vector<int>>& result, TreeNode*& root, vector<int> vec, int targ, int sum){
        if(!root)return;
        if(!root->left && !root->right){
            if(sum+root->val==targ){
                vec.push_back(root->val);
                result.push_back(vec);
            }
            return;
        }
        vec.push_back(root->val);
        fillIt(result, root->left, vec, targ, sum+root->val);
        fillIt(result, root->right, vec, targ, sum+root->val);
    }
};