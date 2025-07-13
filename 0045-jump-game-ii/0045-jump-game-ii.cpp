class Solution {
public:
    int jump(vector<int>& nums) {
        unordered_map<int,long long> map;
        return check(nums, 0, map);
    }

    long long check(vector<int>& nums,int idx, unordered_map<int,long long>& map){
        if(idx == nums.size()-1){
            return 0;
        }
        if(map.count(idx)){
            return map[idx];
        }
        long long currMin = INT_MAX;
        for(int i=1; i<=nums[idx]; i++){
            if(idx+i >= nums.size())continue;
            long long val = check(nums, idx+i, map);
            currMin = min(currMin, val+1);
        }
        map[idx] = currMin;
        return currMin;
    }
};