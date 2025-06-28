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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* addable = new TreeNode();
            addable->val = val;
            addable->left = root;
            addable->right = nullptr;
            return addable;
        }
        check(root, val, depth-1, 1);
        return root;
    }

    void check(TreeNode*& root, int& val, int depth, int curr){
        if(!root)return;
        if(curr == depth){
            TreeNode* addable = new TreeNode();
            addable->val = val;
            addable->left = root->left;
            addable->right = nullptr;
            root->left = addable;

            TreeNode* addable1 = new TreeNode();
            addable1->val = val;
            addable1->left = nullptr;
            addable1->right = root->right;
            root->right = addable1;

            return;
        }
        check(root->left, val, depth, curr+1);
        check(root->right, val, depth, curr+1);
    }
};