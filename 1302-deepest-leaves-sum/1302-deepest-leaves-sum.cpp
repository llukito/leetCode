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
    int deepestLeavesSum(TreeNode* root) {
        map<int,int> mp;
        fill(mp, root, 0);
        return prev(mp.end())->second;
    }

    void fill(map<int,int>& mp, TreeNode* root, int depth){
        if(!root){
            return;
        }
        mp[depth]+=root->val;
        fill(mp, root->left, depth+1);
        fill(mp, root->right, depth+1);
    }
};