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
    bool isCousins(TreeNode* root, int x, int y) {
        int parent1 = 0; int depth1 = 0;
        fill(root, parent1, depth1, x, 0, -1);
        int parent2 = 0; int depth2 = 0;
        fill(root, parent2, depth2, y, 0, -1);
        return parent1 != parent2 && depth1 == depth2;
    }

    void fill(TreeNode* root, int& parent, int& depth, int& val, int d, int p){
        if(!root)return;
        if(root->val == val){
            depth = d;
            parent = p;
            return;
        }
        fill(root->left, parent, depth, val, d+1, root->val);
        fill(root->right, parent, depth, val, d+1, root->val);
    }
};