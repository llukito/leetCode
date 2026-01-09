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
    TreeNode* res = NULL;
    int max_depth = 0;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        helperfirst(root, 0);
        helper(root, 0);
        return res;
    }

    void helperfirst(auto& root, int d){
        if(root == NULL)return;
        helperfirst(root->left, d+1);
        helperfirst(root->right, d+1);
        max_depth = max(max_depth, d);
    }

    int helper(auto& root, int depth){
        if(root == NULL){
            return depth-1;
        }
        auto res1 = helper(root->left, depth+1);
        auto res2 = helper(root->right, depth+1);
        if(root->val == 2){
            cout<<res1<<endl;
        }
        if(res1 == res2 && res1 == max_depth){
            res = root;
        }
        return max(res1, res2);
    }
};
