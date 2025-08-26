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
    int edge = -1;
    int leaves = 0;
    int countPairs(TreeNode* root, int distance) {
        edge = distance;
        unordered_map<TreeNode*, TreeNode*> map;
        fill(root, map, nullptr);
        int res = 0;
        check(res, map, root);
        res-=leaves;
        return res/2;
    }

    void calc(auto root, int& res, auto& map, int dist, auto& set){
        if(!root)return;
        if(dist>edge)return;
        if(set.count(root))return;
        set.insert(root);
        if(!root->left && !root->right){
            res++;
        }
        calc(root->left, res, map, dist+1, set);
        calc(root->right, res, map, dist+1, set);
        calc(map[root], res,  map, dist+1, set);
    }

    void check(int& res, auto& map, auto& root){
        if(!root)return;
        if(!root->left && !root->right){
            leaves++;
            unordered_set<TreeNode*> set;
            calc(root, res, map, 0, set);
            return;
        }
        check(res, map,root->left);
        check(res, map,root->right);
    }

    void fill(TreeNode* root, auto& map, auto parent){
        if(!root)return;
        map[root] = parent;
        fill(root->left, map, root);
        fill(root->right, map, root);
    }
};