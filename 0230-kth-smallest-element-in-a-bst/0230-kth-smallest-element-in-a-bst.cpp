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
    int kthSmallest(TreeNode* root, int k) {
        multiset<int> vect;
        fill(vect, root);
        int lvl = 1;
        for(int n : vect){
            if(lvl == k){
                return n;
            }
            lvl++;
        }
        return -1; // will never get here
    }

    void fill(multiset<int>& vect, TreeNode* root){
        if(!root){
            return;
        }
        vect.insert(root->val);
        fill(vect, root->left);
        fill(vect, root->right);
    }
};