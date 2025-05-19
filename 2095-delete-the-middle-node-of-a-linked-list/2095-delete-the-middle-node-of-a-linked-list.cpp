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
    ListNode* deleteMiddle(ListNode* head) {
        int size = getSize(head);
        int mid = size/2;
        int c = 1;
        if(size == 1){
            return nullptr;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr){
            if(c == mid){
                prev->next = curr->next;
                break;
            }
            prev = curr;
            curr = curr->next;
            c++;
        }
        return head;
    }

    int getSize(ListNode* head){
        int sum = 0;
        while(head){
            sum++;
            head = head->next;
        }
        return sum;
    }
};