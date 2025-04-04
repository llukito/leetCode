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
    int findTilt(TreeNode* root) {
        int sum = 0;
        fill(root, sum);
        return sum;
    }

    void fill(TreeNode*& root, int& sum){
        if(root==nullptr)return;
        sum+=abs(through(root->left) - through(root->right));
        fill(root->left, sum);
        fill(root->right, sum);
    }

    int through(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        return node->val+through(node->left)+through(node->right);
    }
};