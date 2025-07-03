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
class CBTInserter {
public:

    TreeNode* root = nullptr;

    void getMax(int& depth, TreeNode* root, int d, int& num){
        if(!root)return;
        if(!root->left && !root->right){
            if(d>depth){
                depth = d;
                num = 1;
            } else if(d==depth){
                num++;
            }
            return;
        }
        getMax(depth, root->left, d+1, num);
        getMax(depth, root->right, d+1, num);
    }

    CBTInserter(TreeNode* root) {
        this->root = root;
    }
    
    void ins(TreeNode*& root, int val, int depth, int d, bool& b, int& parent, int p){
        if(!b)return;
        if(d == depth){
            if(!root){
                root = new TreeNode(val);
                parent = p;
                b = false;
            }
            return;
        }
        ins(root->left, val, depth, d+1, b, parent, root->val);
        ins(root->right, val, depth, d+1,b, parent, root->val);
    }

    int insert(int val) {
        int maxDepth = 0;
        int num = 0;
        getMax(maxDepth, root, 0, num);
        int count = pow(2, maxDepth);
        int toadd = -1;
        if(num == count){
            toadd = maxDepth+1;
        } else {
            toadd = maxDepth;
        }
        cout<<maxDepth<<" "<<num<<endl;
        bool b = true;
        int parent = -1;
        ins(root, val, toadd, 0, b, parent, -1);
        return parent;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */