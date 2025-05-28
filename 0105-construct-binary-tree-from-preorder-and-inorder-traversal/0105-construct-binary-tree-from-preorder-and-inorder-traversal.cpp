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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;
        for(int i=0; i<inorder.size(); i++){
            inorderIndex[inorder[i]]=i;
        }
        int preIndex = 0;
        return check(inorderIndex, preIndex, preorder, inorder, 0, preorder.size()-1);
    }

    TreeNode* check(unordered_map<int, int>& inorderIndex, int& preIndex, vector<int>& preorder, vector<int>& inorder, int left, int right){
        if(left > right){
            return nullptr;
        }
        int val = preorder[preIndex++];
        TreeNode* node = new TreeNode(val);
        int idx = inorderIndex[val];
        node->left = check(inorderIndex, preIndex, preorder, inorder, left, idx-1 );
        node->right = check(inorderIndex, preIndex, preorder, inorder, idx+1, right);
        return node;
    }
};