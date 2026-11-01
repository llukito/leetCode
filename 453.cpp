class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0;
        multiset<int> st;
        for(int n : nums){
            st.insert(n);
        }
        while(true){
            int first = *st.begin();
            int last = *st.rbegin();
            if(first == last){
                break;
            }
            st.erase(prev(st.end()));
            st.insert(last-(last-first));
            res += last-first;
        }
        return res;
    }
};
