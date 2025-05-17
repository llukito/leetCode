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
    ListNode* swapNodes(ListNode* head, int k) {
        int size = getSize(head);
        vector<ListNode*> pair;
        check(head, k, size-k+1, 1, pair);
        swap(pair[0]->val, pair[1]->val);
        return head;
    }

    void check(ListNode* head, int k, int m, int l, vector<ListNode*>& pair){
        if(pair.size()==2)return;
        if(!head)return;
        if(l == k){
            pair.push_back(head);
        }
        if(l == m){
            pair.push_back(head);
        }
        check(head->next, k, m, l+1, pair);
    }

    int getSize(ListNode* head){
        if(!head)return 0;
        return 1+getSize(head->next);
    }
};