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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> vect;
        while(head){
            vect.push_back(head->val);
            head = head->next;
        }
        sort(vect.begin(), vect.end());
        ListNode* nd = new ListNode(-1);
        ListNode* r = nd;
        for(int n : vect){
            ListNode* node = new ListNode(n);
            r->next = node;
            r = r->next;
        }
        return nd->next;
    }
};