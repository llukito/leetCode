class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        fill(root->left, root->right, 1);
        return root;
    }

    void fill(TreeNode* left, TreeNode* right, int depth){
        if (!left || !right) return;
        
        if (depth % 2 == 1) {
            swap(left->val, right->val);
        }
        
        fill(left->left, right->right, depth + 1);
        fill(left->right, right->left, depth + 1);
    }
};
