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
    int getDecimalValue(ListNode* head) {
        int size = getSize(head);
        int res = 0;
        while(head){
            res+=head->val*pow(2, size-1);
            head = head->next;
            size--;
        }
        return res;
    }

    int getSize(ListNode* head){
        int b = 0;
        while(head){
            b++;
            head = head->next;
        }
        return b;
    }
};