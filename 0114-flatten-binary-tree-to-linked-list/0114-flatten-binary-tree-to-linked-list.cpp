class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        vector<TreeNode*> nodes;
        preorder(root, nodes);

        for (int i = 0; i < nodes.size() - 1; ++i) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }
        nodes.back()->left = nullptr;
        nodes.back()->right = nullptr;
    }

    void preorder(TreeNode* node, vector<TreeNode*>& nodes) {
        if (!node) return;

        nodes.push_back(node);
        preorder(node->left, nodes);
        preorder(node->right, nodes);
    }
};
