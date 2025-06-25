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
class FindElements {
public:
    TreeNode* head;
    FindElements(TreeNode* root) {
        head = root;
        recover(head, 0);
    }

    void recover(TreeNode* head, int val){
        if(!head)return;
        head->val = val;
        if(head->left){
            recover(head->left, val*2+1);
        }
        if(head->right){
            recover(head->right, val*2+2);
        }
    }
    
    bool find(int target) {
        return findIt(head, target);
    }

    bool findIt(TreeNode* head, int target){
        if(!head)return false;
        if(head->val == target)return true;
        if(findIt(head->left, target))return true;
        if(findIt(head->right, target))return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */