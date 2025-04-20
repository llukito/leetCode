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
    int averageOfSubtree(TreeNode* root) {
        int num = 0;
        fill(num, root);
        return num;
    }

    void fill(int& num, TreeNode* nd){
        if(!nd)return;
        int sum1 = 0;
        int q = 0;
        sum(nd, sum1, q);
        if(nd->val == sum1/q){
            num++;
        }
        fill(num, nd->left);
        fill(num, nd->right);
    }

    void sum(TreeNode* nd, int& sum1, int& q){
        if(nd==nullptr)return;
        sum1+=nd->val;
        q++;
        sum(nd->left, sum1, q);
        sum(nd->right, sum1, q);
    }
};