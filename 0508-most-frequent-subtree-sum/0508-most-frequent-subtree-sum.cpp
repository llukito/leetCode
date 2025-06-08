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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> map;
        int maxFreq = 0;
        fill(map, root, maxFreq);
        vector<int> result;
        for(auto& entry : map){
            if(entry.second == maxFreq){
                result.push_back(entry.first);
            }
        }
        return result;
    }

    void fill(unordered_map<int,int>& map, TreeNode* root, int& maxFreq){
        if(!root)return;
        int curr = getSum(root);
        map[curr]++;
        maxFreq = max(maxFreq, map[curr]);
        fill(map, root->left, maxFreq);
        fill(map, root->right, maxFreq);
    }

    int getSum(TreeNode* root){
        if(!root)return 0;
        return root->val + getSum(root->left)+getSum(root->right);
    }

};