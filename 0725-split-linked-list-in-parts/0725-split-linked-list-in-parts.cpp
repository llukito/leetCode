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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        int size = getSize(head);
        int starts = size%k;
        int norm = size/k;

        for(int i=0; i<starts; i++){
            ListNode* dump = new ListNode(-1);
            ListNode* node = dump;
            for(int j=0; j<norm+1; j++){
                node->next = head;
                node = head;
                head = head->next;
            }
            node->next = nullptr;
            result.push_back(dump->next);
        }

        for(int i=0; i<k - starts; i++){
            ListNode* dump = new ListNode(-1);
            ListNode* node = dump;
            for(int j=0; j<norm; j++){
                if(head){
                    node->next = head;
                    node = head;
                    head = head->next;
                } else {
                    break;
                }
            }
            if(dump->next && dump->next->val !=-1){
                node->next = nullptr;
                result.push_back(dump->next);
            } else {
                result.push_back(nullptr);
            }
        }

        return result;
    }

    int getSize(ListNode* head){
        int sum = 0;
        while(head!=nullptr){
            sum++;
            head = head->next;
        }
        return sum;
    }
};