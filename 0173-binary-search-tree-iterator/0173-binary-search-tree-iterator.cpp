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
class BSTIterator {
public:

    vector<int> vect;
    int index = 0;

    void fill(TreeNode* root){
        if(!root){
            return;
        }
        fill(root->left);
        vect.push_back(root->val);
        fill(root->right);
    }

    BSTIterator(TreeNode* root) {
        fill(root);
    }
    
    int next() {
        return vect[index++];
    }
    
    bool hasNext() {
        return index<vect.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */