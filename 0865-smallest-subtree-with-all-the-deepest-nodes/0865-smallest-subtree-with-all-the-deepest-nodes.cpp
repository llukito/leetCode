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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int depth = 0;
        getDepth(depth, root, 0);
        unordered_set<TreeNode*> set;
        store(root, depth, set, 0);
        return helper(root, set);
    }

    void store(TreeNode* root, int& depth, unordered_set<TreeNode*>& set, int curr){
        if(!root)return;
        if(curr == depth){
            set.insert(root);
        }
        store(root->left, depth, set, curr+1);
        store(root->right, depth, set, curr+1);
    }

    void getDepth(int& depth, TreeNode* root, int curr){
        if(!root)return;
        depth = max(depth, curr);
        getDepth(depth, root->left, curr+1);
        getDepth(depth, root->right, curr+1);
    }

    TreeNode* helper(TreeNode* root,unordered_set<TreeNode*>& set){
        if(!root || set.count(root))return root;
        TreeNode* nd1 = helper(root->left, set);
        TreeNode* nd2 = helper(root->right, set);
        if(nd1 && nd2)return root;
        if(nd1){
            return nd1;
        }
        return nd2;
    }
};