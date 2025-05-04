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
    int findSecondMinimumValue(TreeNode* root) {
        set<int> st;
        fill(st, root);
        int index = 0;
        for(int n : st){
            if(index==1){
                return n;
            }
            index++;
        }
        return -1;
    }

    void fill(set<int>& st, TreeNode* root){
        if(!root)return;
        st.insert(root->val);
        fill(st, root->left);
        fill(st, root->right);
    }
};
