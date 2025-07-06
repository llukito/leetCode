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
    void flatten(TreeNode* root) {
        check(root);
    }

    pair<TreeNode*, TreeNode*> check(TreeNode* root){
        if(!root){
            return {nullptr, nullptr};
        }
        if(!root->left && !root->right){
            return {root,root};
        }
        TreeNode* temp = root->right;
        TreeNode* temp1 = root->left;
        pair<TreeNode*, TreeNode*> pr{nullptr, nullptr};;
        if(root->left){
            pr = check(root->left);
            root->right = pr.first;
            root->left = nullptr;
        }
         pair<TreeNode*, TreeNode*> pr2 = {nullptr, nullptr};
        if(temp){
            pr2 = check(temp);
            if(pr.second){
                pr.second->right = pr2.first;
                pr.second->left = nullptr;
            }
        }
        return {root, pr2.second ? pr2.second : pr.second ? pr.second : root };
    }
};