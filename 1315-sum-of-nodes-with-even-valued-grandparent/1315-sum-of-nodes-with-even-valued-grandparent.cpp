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
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        fill(root, res);
        return res;
    }

    void fill(TreeNode* root, int& res){
        if(!root)return;
        if(root->val%2==0){
            res+= check(root);
        }
        fill(root->left, res);
        fill(root->right, res);
    }

    int check(TreeNode* root){
        int res = 0;
        if(root->left){
            if(root->left->left){
                res+=root->left->left->val;
            }
            if(root->left->right){
                res+=root->left->right->val;
            }
        }
        if(root->right){
            if(root->right->left){
                res+=root->right->left->val;
            }
            if(root->right->right){
                res+=root->right->right->val;
            }
        }
        return res;
    }
};