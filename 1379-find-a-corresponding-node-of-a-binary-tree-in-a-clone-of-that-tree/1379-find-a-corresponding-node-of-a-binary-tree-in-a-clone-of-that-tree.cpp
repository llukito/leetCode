/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* nd = nullptr;
        check(cloned, target, nd);
        return nd;
    }

    void check(TreeNode* cloned, TreeNode* target, TreeNode*& nd){
        if(nd!=nullptr) return;
        if(!cloned)return;
        if(cloned->val == target->val){
            nd = cloned;
            return;
        }
        check(cloned->left, target, nd);
        check(cloned->right, target, nd);
    }
};