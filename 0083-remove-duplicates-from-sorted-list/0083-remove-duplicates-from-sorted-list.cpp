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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> set;
        ListNode* node = new ListNode(-1);
        ListNode* r = node;
        while(head!=nullptr){
            if(find(set.begin(), set.end(), head->val)==set.end()){
                set.push_back(head->val);
            }
            head = head->next;
        }
        for(int n : set){
            ListNode* nd = new ListNode(n);
            r->next = nd;
            r = r->next;
        }
        r->next = nullptr;
        return node->next;
    }
};