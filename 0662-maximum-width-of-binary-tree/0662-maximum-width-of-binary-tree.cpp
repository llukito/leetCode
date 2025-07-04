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
    const int SENTINEL = -69;
    int maxDepth = 0;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        unordered_map<int,vector<int>> map;
        int max_ = 0;
        getMax(root, 0);
        fill(root, 0, map);
        for(auto& entry : map){
            max_ = max(max_, getIt(entry.second));
        }
        return max_;
    }

    void getMax(TreeNode* root, int depth){
        if(!root){
            return;
        }
        maxDepth = max(maxDepth, depth);
        getMax(root->left, depth+1);
        getMax(root->right, depth+1);
    }   

    void fill(TreeNode* root, int depth, unordered_map<int,vector<int>>& map){
        if(depth > maxDepth)return;
        if(!root){
            map[depth].push_back(SENTINEL);
            fill(root, depth+1, map);
            fill(root, depth+1, map);
        } else {
            map[depth].push_back(root->val);
            fill(root->left, depth+1, map);
            fill(root->right, depth+1, map);
        }
    }

    int getIt(vector<int>& vect){
        int start = -1; int end = -1;
        for(int i=0; i<vect.size(); i++){
            if(vect[i] != SENTINEL){
                if(start == -1 ){
                    start = i;
                } else {
                    end = i;
                }
            }
        }
        if(start == -1 && end == -1)return 0;
        if(start != -1 && end == -1)return 1;
        return end-start+1;
    }
};