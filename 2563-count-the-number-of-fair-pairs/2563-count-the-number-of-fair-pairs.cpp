class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        for(int i=0; i<nums.size()-1; i++){
            int num = nums[i];
            auto it1 = lower_bound(nums.begin()+i+1, nums.end(), lower-num);
            if(it1==nums.end())continue;
            int index1 = it1-nums.begin();
            auto it2 = upper_bound(nums.begin()+i+1, nums.end(), upper-num);
            int index2 = it2-nums.begin();
            if(it2==nums.end()){
                index2 = nums.size();
            }
            res+= index2-index1>0 ? index2-index1 : 0;
        }
        return res;
    }
};