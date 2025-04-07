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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        fill(root, res, "");
        return res;
    }
    
    void fill(TreeNode*& root, vector<string>& res, string curr){
        if(!root)return;
        if(!root->left && !root->right){
            curr+=to_string(root->val);
            res.push_back(curr);
        }
        curr+=to_string(root->val);
        curr+="->";
        fill(root->left, res, curr);
        fill(root->right, res, curr);
    }
};