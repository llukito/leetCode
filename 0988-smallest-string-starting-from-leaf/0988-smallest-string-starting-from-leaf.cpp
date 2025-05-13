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
    string smallestFromLeaf(TreeNode* root) {
        string res;
        string curr;
        fill(root, res, curr);
        return res;
    }

    void fill(TreeNode* root, string& res, string curr){
        if(!root->left && !root->right){
            curr+=(char)('a'+root->val);
            reverse(curr.begin(), curr.end());
            if(res.empty() || curr<res){
                res = curr;
            }
            return;
        }
        if(root->left){
            fill(root->left, res, curr+(char)('a'+root->val));
        }
        if(root->right){
            fill(root->right, res, curr+(char)('a'+root->val));
        }
    }
};