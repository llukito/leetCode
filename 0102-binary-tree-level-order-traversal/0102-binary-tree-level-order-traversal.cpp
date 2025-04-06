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
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int, vector<int>> map2;
        fillMap(map2, root, 0);
        vector<vector<int>> vect;
        for(auto entry : map2){
            vect.push_back(entry.second);
        }
        return vect;
    }

    void fillMap(map<int, vector<int>>& map2, TreeNode*& root, int depth){
        if(root==nullptr)return;
        map2[depth].push_back(root->val);
        fillMap(map2, root->left, depth+1);
        fillMap(map2, root->right, depth+1);
    }
};