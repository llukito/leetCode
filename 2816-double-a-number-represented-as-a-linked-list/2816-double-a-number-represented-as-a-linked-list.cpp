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
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = head;
        while(temp){
            temp->val*=2;
            temp = temp->next;
        }
        temp = head;
        stack<ListNode*> st;
        while (temp) {
            st.push(temp);
            temp = temp->next;
        }
        while(!st.empty()){
            ListNode* nd = st.top(); st.pop();
            int n = nd->val%10;
            int m = (nd->val - n)/10;
            nd->val = n;
            if(!st.empty()){
                st.top()->val +=m;
            } else {
                if(m!=0){
                    nd->val = n;
                    ListNode* nd = new ListNode(m);
                    nd->next = head;
                    head = nd;
                }
            }
        }
        return head;
    }
};