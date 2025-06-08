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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vect;
        fill(vect, root);
        sort(vect.begin(), vect.end());
        TreeNode* res = nullptr;
        return  makeBST(vect, res, 0, vect.size()-1);
    }

    TreeNode* makeBST(vector<int>& vect, TreeNode* root, int left, int right){
        if(left > right)return nullptr;
        int mid = left + (right-left)/2;
        root = new TreeNode(vect[mid]);
        root->left = makeBST(vect, root->left, left, mid-1);
        root->right = makeBST(vect, root->right, mid+1, right);
        return root;
    }

    void fill(vector<int>& vect, TreeNode* root){
        if(!root)return;
        vect.push_back(root->val);
        fill(vect, root->left);
        fill(vect, root->right);
    }
};