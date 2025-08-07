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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        while(true){
            bool b = true;
            edit(root, target, b);
            if(b)break;
        }
        return root;
    }

    void edit(TreeNode*& root, int target, bool& b){
        if(!root)return;
        if(!root->left && !root->right && root->val == target){
            root = nullptr;
            b = false;
            return;
        }
        edit(root->left, target, b);
        edit(root->right, target, b);
    }
};