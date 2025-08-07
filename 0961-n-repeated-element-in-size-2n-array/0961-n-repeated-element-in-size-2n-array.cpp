class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> st;
        for(int n : nums){
            if(st.count(n))return n;
            st.insert(n);
        }
        return -1;
    }
};