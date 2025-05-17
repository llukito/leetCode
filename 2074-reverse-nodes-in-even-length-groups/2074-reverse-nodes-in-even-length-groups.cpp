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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int size = 1;
        ListNode* h = head;
        while(head){
            vector<ListNode*> vect;
            int realSize = 0;
            for(int i=0; i<size; i++){
                if(!head)break;
                vect.push_back(head);
                head = head->next;
                realSize++;
            }
            if(realSize%2 == 0){
                for(int i=0; i<vect.size()/2; i++){
                    swap(vect[i]->val, vect[vect.size()-1-i]->val);
                }
            }
            size++;
        }
        head = h;
        return head;
    }
};