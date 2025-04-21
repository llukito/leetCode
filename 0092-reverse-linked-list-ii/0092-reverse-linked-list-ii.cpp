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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> vect;
        while(head!=nullptr){
            vect.push_back(head->val);
            head = head->next;
        }
        reverse(vect.begin()+left-1,  vect.begin()+right);
        ListNode* dum = new ListNode(-1);
        ListNode* r = dum;
        for(int n : vect){
            ListNode* nd = new ListNode(n);
            r->next = nd;
            r = r->next;
        }
        r->next = nullptr;
        return dum->next;
    }
};