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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> deepest;
        int maxDepth = 0;
        findDeepestLeaves(root, 0, maxDepth, deepest);
        TreeNode* copyOfRoot = root;
        TreeNode* result=nullptr;
        return findIt(deepest, copyOfRoot);
    }

    TreeNode* findIt(vector<TreeNode*> deepest, TreeNode* nd){    
        if(nd==nullptr || find(deepest.begin(), deepest.end(), nd)!=deepest.end()){
            return nd;
        }

        TreeNode* right = findIt(deepest, nd->right);
        TreeNode* left = findIt(deepest, nd->left);

        if(right!=nullptr && left!=nullptr){
            return nd;
        }

        return right!=nullptr ? right : left;
    }

    void findDeepestLeaves(TreeNode* node, int depth, int& maxDepth, vector<TreeNode*>& deepestLeaves) {
    if (!node) return;
    if (!node->left && !node->right) {
        if (depth > maxDepth) {
            maxDepth = depth; 
            deepestLeaves.clear();
            deepestLeaves.push_back(node); 
        } else if (depth == maxDepth) {
            deepestLeaves.push_back(node);
        }
    }
    findDeepestLeaves(node->left, depth + 1, maxDepth, deepestLeaves);
    findDeepestLeaves(node->right, depth + 1, maxDepth, deepestLeaves);
}

};