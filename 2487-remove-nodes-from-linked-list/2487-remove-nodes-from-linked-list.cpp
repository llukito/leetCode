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
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> vec;
        fill(vec, head);
        vector<int> dp;
        dp.push_back(vec.back()->val);
        for(int i=vec.size()-2; i>=0; i--){
            dp.push_back(max(dp.back(), vec[i]->val));
        }
        reverse(dp.begin(), dp.end());
        ListNode* d = new ListNode(-1);
        ListNode* res = d;
        for(int i=0; i<vec.size(); i++){
            if(vec[i]->val >= dp[i]){
                res->next = vec[i];
                res = res->next;
            }
        }
        res->next = nullptr;
        return d->next;
    }

    void fill(vector<ListNode*>& vec, ListNode* hd){
        while(hd!=nullptr){
            vec.push_back(hd);
            hd = hd->next;
        }
    }
};