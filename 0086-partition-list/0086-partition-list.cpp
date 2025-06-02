/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> vect1;
        vector<int> vect2;
        fill1(vect1, vect2, head, x);
        ListNode* r = new ListNode();
        ListNode* n = r;
        for(int i : vect1){
            ListNode* nd = new ListNode(i);
            n->next = nd;
            n = n->next;
        }
        for(int i : vect2){
            ListNode* nd = new ListNode(i);
            n->next = nd;
            n = n->next;
        }
        return r->next;
    }

    void fill1(vector<int>& vect1, vector<int>& vect2, ListNode* head, int& x){
        if(!head)return;
        if(head->val < x){
            vect1.push_back(head->val);
        } else {
            vect2.push_back(head->val);
        }
        fill1(vect1, vect2, head->next, x);
    }
};