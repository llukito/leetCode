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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* result = nullptr;
        fill(result, root1, root2);
        return result;
    }

    void fill(TreeNode*& result, TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2){
            result = nullptr;
            return;
        }
        if(root1 && root2){
            result = new TreeNode();
            result->val = root1->val + root2->val;
            result->left = result->right = nullptr;
            fill(result->left, root1->left, root2->left);
            fill(result->right, root1->right, root2->right);
        } else if(root1){
           result = new TreeNode();
            result->val = root1->val;
            result->left = result->right = nullptr;
            fill(result->left, root1->left, root2);
            fill(result->right, root1->right, root2);
        } else {
            result = new TreeNode();
            result->val = root2->val;
            result->left = result->right = nullptr;
            fill(result->left, root1, root2->left);
            fill(result->right, root1, root2->right);
        }
    }
};