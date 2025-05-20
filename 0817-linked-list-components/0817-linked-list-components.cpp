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
    int numComponents(ListNode* head, vector<int>& nums) {
        vector<int> vect;
        while(head){
            vect.push_back(head->val);
            head = head->next;
        }
        set<int> st;
        if(nums.empty())return 0;
        int val = 0;
        for(int n : nums){
            int index = find(vect.begin(), vect.end(), n)-vect.begin();
            if(st.count(n)){
                
            } else {
                st.insert(n);
                if(index+1<vect.size()){
                    st.insert(vect[index+1]);
                }
                if(index-1>=0){
                    st.insert(vect[index-1]);
                }
                val++;
            }
        }
        return val;
    }
};