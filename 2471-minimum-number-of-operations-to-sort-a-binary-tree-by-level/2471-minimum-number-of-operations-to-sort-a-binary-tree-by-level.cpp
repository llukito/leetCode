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
    int minimumOperations(TreeNode* root) {
        unordered_map<int,vector<int>> map;
        fill(map, root, 0);
        int res = 0;
        for(auto& entry : map){
            vector<int> vect = entry.second;
            vector<int> vect2;
            unordered_map<int, int> m1;
            unordered_map<int, int> m2;
            for(int i=0; i<vect.size(); i++){
                m1[vect[i]] = i;
                vect2.push_back(vect[i]);
            }
            sort(vect2.begin(), vect2.end());
            for(int i=0; i<vect2.size(); i++){
                m2[i] = vect2[i];
            }
            for(int i=0; i<vect.size(); i++){
                if(vect[i]!=vect2[i]){
                    int idx = m1[vect2[i]];
                    swap(vect[idx], vect[i]);
                    m1[vect2[i]] = i;
                    m1[vect[idx]] = idx;
                    res++;
                }
            }
        }
        return res;
    }

    void fill(unordered_map<int,vector<int>>& map, TreeNode* root, int depth){
        if(!root)return;
        map[depth].push_back(root->val);
        fill(map, root->left, depth+1);
        fill(map, root->right, depth+1);
    }
};