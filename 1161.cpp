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
    int maxLevelSum(TreeNode* root) {
        int res = 0;
        int sum = INT_MIN;
        unordered_map<int, int> mp;
        check(root, mp, 0);
        for(auto& en : mp){
            if(en.second > sum){
                sum = en.second;
                res = en.first;
            } else if((en.second == sum) && (res > en.first)){
                res = en.first;
            }
        }
        return res+1;
    }

    void check(auto root, auto& mp, int depth){
        if(!root)return;
        mp[depth]+=root->val;
        check(root->left, mp, depth+1);
        check(root->right, mp, depth+1);
    }
};
