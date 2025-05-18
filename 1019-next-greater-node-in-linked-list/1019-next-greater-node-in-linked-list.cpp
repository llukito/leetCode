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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        while(head){
            if(!head->next){
                res.push_back(0);
                break;
            } else {
                int curr = head->val;
                int num = 0;
                ListNode* nd = head->next;
                while(nd){
                    if(nd->val > curr){
                        num = nd->val;
                        break;
                    }
                    nd = nd->next;
                }
                res.push_back(num);
                head = head->next;
            }
        }
        return res;
    }
};