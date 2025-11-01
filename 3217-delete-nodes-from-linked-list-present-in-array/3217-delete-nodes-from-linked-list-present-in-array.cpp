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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* nd = head;
        ListNode* prev = nullptr;
        while(nd){
            if(st.count(nd->val)){
                if(prev){
                    prev->next = nd->next;
                } else {
                    head = head->next;
                }
                nd = nd->next;
            } else {
                prev = nd;
                nd = nd->next;
            }
        }
        return head;
    }
};