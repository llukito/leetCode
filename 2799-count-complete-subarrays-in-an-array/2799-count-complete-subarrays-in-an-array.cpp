class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s;
        for(int n : nums){
            s.insert(n);
        }
        int k = s.size();
        int res = 0;
        unordered_map<int,int> mp;
        int left = 0; int right = 0;
        while(right<nums.size() && left<nums.size()){
            mp[nums[right++]]++;
            if(mp.size()==k){
                res++;
            }
            if(right==nums.size()){
                left++;
                right=left;
                mp.clear();
            }
        }
        return res;
    }
};