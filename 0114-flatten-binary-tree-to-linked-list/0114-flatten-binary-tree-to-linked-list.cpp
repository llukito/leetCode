class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)return;
        TreeNode* head = nullptr;
        TreeNode* tail = nullptr;
        fill(root->left, head, tail);
        root->left = nullptr;
        TreeNode* temp = root->right;
        root->right = head; 

        TreeNode* head2 = nullptr;
        TreeNode* tail2 = nullptr;
        fill(temp, head2, tail2);
        if(tail){
            tail->right = head2; 
        } else {
            root->right = head2;
        }
    }
    
    void fill(TreeNode* root, TreeNode*& head, TreeNode*& tail) {
        if (!root) return;
        TreeNode* nd = new TreeNode();
        nd->val = root->val; nd->left = nullptr; nd->right = nullptr;
        if(!head){
            head = nd;
            tail = nd;
        } else {
            tail->right = nd;
            tail = nd;
        }
        fill(root->left, head, tail);
        fill(root->right, head, tail);
    }

    void freeTree(TreeNode*& root){
        if(!root)return;
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
};
