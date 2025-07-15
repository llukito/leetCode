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
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        int carry = 0;
        ListNode* root = head;
        while(root){
            int val = root->val*2 + carry;
            int nextVal = val%10;
            int currVal = (val-nextVal)/10;
            root->val = nextVal;
            carry = currVal;
            root = root->next;
        }
        head = reverse(head);
        if(carry != 0){
            ListNode* addable = new ListNode();
            addable->val = carry;
            addable->next = head;
            head = addable;
        }
        return head;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head  = temp;
        }
        return prev;
    }
};