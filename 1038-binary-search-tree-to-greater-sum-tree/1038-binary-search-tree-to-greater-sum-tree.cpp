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
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> vec;
        TreeNode* nd = root;
        fillAll(vec, nd);
        fill(root, vec);
        return root;
    }
    
    void fillAll(vector<int>& vec, TreeNode* nd){
        if(!nd)return;
        vec.push_back(nd->val);
        fillAll(vec, nd->left);
        fillAll(vec, nd->right);
    }

    void fill(TreeNode*& root, vector<int>& vec){
        if(!root)return;
        int sum =root->val;
        for(int n : vec){
            if(n>root->val){
                sum+=n;
            }
        }
        root->val = sum;
        fill(root->left, vec);
        fill(root->right, vec);
    }
};