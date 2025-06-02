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
    int pairSum(ListNode* head) {
        stack<int> st;
        fill(st,head);
        int n = st.size()/2;
        int num = -1;
        while(n){
            num = max(num, head->val + st.top());
            n--;
            head = head->next;
            st.pop();
        }
        return num;
    }

    void fill(stack<int>& st, ListNode* head){
        if(!head)return;
        st.push(head->val);
        fill(st, head->next);
    }
};