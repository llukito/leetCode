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
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        return findIt(root,1);
    }

    int findIt(TreeNode*& root, int depth){
        if(!root)return INT_MAX;
        if(!root->left && !root->right){
            return depth;
        }
        int n1 = findIt(root->left, depth+1);
        int n2 = findIt(root->right, depth+1);
        return min(n1,n2);
    }
};