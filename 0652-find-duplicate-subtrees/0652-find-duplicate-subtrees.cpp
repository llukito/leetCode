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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> map;
        fill(map, root);
        vector<TreeNode*> vect;
        for(auto& entry : map){
            if(entry.second.size()>1){
                cout<<entry.first<<endl;
                vect.push_back(entry.second[0]);
            }
        }
        return vect;
    }

    string fill(unordered_map<string, vector<TreeNode*>>& map, TreeNode* root){
        if(!root)return "^";
        string key = "/" + fill(map, root->left) + "," + to_string(root->val) + "." +  fill(map, root->right) + "/";
        map[key].push_back(root);
        return key;
    }
};