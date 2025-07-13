class Solution {
public:
    bool canJump(vector<int>& nums) {
        unordered_map<int,bool> map;
        return check(nums, 0, map);
    }

   bool check(vector<int>& nums,int idx, unordered_map<int,bool>& map){
        if(idx == nums.size()-1){
            return true;
        }
        if(map.count(idx)){
            return map[idx];
        }
        for(int i=1; i<=nums[idx]; i++){
            if(idx+i >= nums.size())continue;
            if(check(nums, idx+i, map)){
                map[idx] = true;
                return true;
            }
        }
        map[idx] = false;
        return false;
    }
};