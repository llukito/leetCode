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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = nullptr;
        for(int i=0; i<preorder.size(); i++){
            insert(root, preorder[i]);
        }
        return root;
    }

    void insert(TreeNode*& root, int val){
        if(!root){
            root = new TreeNode(val);
            return;
        }
        if(val>root->val){
            insert(root->right, val);
        } else {
            insert(root->left, val);
        }
    }
};