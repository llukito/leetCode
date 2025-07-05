/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    struct Node{
        Node* next;
        int val;
        Node(){
            next = nullptr;
            val = -1;
        }
    };

    Node* root = new Node();
    Node* head = root;

    void fill(vector<NestedInteger> &nestedList){
        for(NestedInteger in : nestedList){
            if(in.isInteger()){
                Node* addable = new Node();
                addable->val = in.getInteger();
                addable->next = nullptr;
                head->next = addable;
                head = addable;
            } else {
                fill(in.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        fill(nestedList);
    }
    
    int next() {
        int val = root->next->val;
        root = root->next;
        return val;
    }
    
    bool hasNext() {
        return root->next;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */