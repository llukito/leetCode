class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        vector<int> prefix(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); i++)prefix[i+1] = prefix[i] + nums[i];
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            unordered_set<int> st;
            for(int j = i; j < nums.size(); j++){
                st.insert(nums[j]);
                int sum = prefix[j+1]-prefix[i];
                if(st.count(sum))res++;
            }
        }
        return res;
    }
};
