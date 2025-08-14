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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0)return {};
        if(n==1)return {new TreeNode(0)};
        vector<TreeNode*> res;
        for(int l=1; l<n-1; l++){
            int r = n-l-1;
            for(TreeNode* left : allPossibleFBT(l)){
                for(TreeNode* right : allPossibleFBT(r)){
                    TreeNode* node = new TreeNode(0);
                    node->left = left; node->right = right;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};