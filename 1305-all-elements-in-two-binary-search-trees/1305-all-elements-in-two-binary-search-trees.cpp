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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        fill(res, root1);
        fill(res, root2);
        sort(res.begin(), res.end());
        return res;
    }

    void fill(vector<int>& res, TreeNode* node){
        if(!node)return;
        res.push_back(node->val);
        fill(res, node->left);
        fill(res, node->right);
    }
};