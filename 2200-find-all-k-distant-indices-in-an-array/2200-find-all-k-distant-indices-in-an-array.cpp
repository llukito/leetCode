class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        set<int> st;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == key){
                for(int j=0; j<nums.size(); j++){
                    if(abs(j-i)<=k){
                        st.insert(j);
                    }
                }
            }
        }
        for(int n : st){
            res.push_back(n);
        }
        return res;
    }
};