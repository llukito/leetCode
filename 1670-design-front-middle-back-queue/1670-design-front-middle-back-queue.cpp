class FrontMiddleBackQueue {
public:
struct Node{
    Node* left;
    Node* right;
    int val;
};
    int size;
    Node* head;
    Node* tail;
    FrontMiddleBackQueue() {
        size = 0;
        head = new Node();
        head->left = head->right = nullptr;
        head->val = 0;
        tail = new Node();
        tail->left = tail->right = nullptr;
        tail->val = 0;
        head->right = tail;
        tail->left = head;
    }
    
    void pushFront(int val) {
        Node* nd = new Node();
        nd->val = val;
        nd->left = head;
        nd->right = head->right;
        if(head->right){
            head->right->left = nd;
        }
        head->right = nd;
        size++;
    }
    
    void pushMiddle(int val) {
        if(size == 0){
            pushFront(val);
            return;
        }
        int s = size/2;
        Node* r = head->right;
        while(s){
            r = r->right;
            s--;
        }
        Node* nd = new Node();
        nd->val = val; nd->left = nd->right = nullptr;
        Node* temp = r->left;
        r->left = nd;
        nd->right = r;

        temp->right = nd;
        nd->left = temp;
        size++;
    }
    
    void pushBack(int val) {
        Node* nd = new Node();
        nd->val = val;
        nd->right = tail;
        nd->left = tail->left;
        if(tail->left){
            tail->left->right = nd;
        }
        tail->left = nd;
        size++;
    }
    
    int popFront() {
        if(size == 0)return -1;
        Node* nd = head->right;
        int v = nd->val;
        if(head->right->right){
            head->right->right->left = head;
        }
        head->right = head->right->right;
        delete nd;
        size--;
        return v;
    }
    
    int popMiddle() {
        if(size == 0)return -1;
        int s = size/2;
        if(size%2==0)s--;
        Node* r = head->right;
        while(s){
            r = r->right;
            s--;
        }
        int val = r->val;
        r->left->right = r->right;
        r->right->left = r->left;
        size--;
        delete r;
        return val;
    }
    
    int popBack() {
        if(size == 0)return -1;
        Node* nd = tail->left;
        int v = nd->val;
        if(tail->left->left){
            tail->left->left->right = tail;
        }
        tail->left = tail->left->left;
        delete nd;
        size--;
        return v;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */