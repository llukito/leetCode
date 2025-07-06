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
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        check(root, res, "");
        return res;
    }

    void check(TreeNode* root, int& res, string curr){
        if(!root)return;
        if(!root->left && !root->right){
            curr+=to_string(root->val);
            res+=convert(curr);
            return;
        }
        check(root->left, res, curr+to_string(root->val));
        check(root->right, res, curr+to_string(root->val));
    }

    int convert(string curr){
        int res = 0;
        for(int i=0; i<curr.length(); i++){
            res+=(curr[i]-'0')*pow(2, curr.length()-i-1);
        }
        return res;
    }
};