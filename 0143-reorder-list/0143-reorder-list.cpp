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
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        while(head!=nullptr){
            vec.push_back(head);
            head = head->next;
        }
        ListNode* nd = new ListNode(-1);
        ListNode* r = nd;
        for(int i=0; i<vec.size()/2; i++){
            r->next = vec[i];
            r = r->next;
            r->next = vec[vec.size()-i-1];
            r = r->next;
        }
        if(vec.size()%2==1){
            r->next = vec[vec.size()/2];
            r = r->next;
        }
        r->next = nullptr;
        head = r->next;
    }
    
    void fill(ListNode* head){

    }
};