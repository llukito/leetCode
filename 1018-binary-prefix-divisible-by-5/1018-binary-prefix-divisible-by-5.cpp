class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res(nums.size(), false);
        int curr = 0;
        for(int i = 0; i < nums.size(); i++){
            curr*=2;
            curr+=nums[i];
            if(!(curr%5))res[i] = 1;
        }
        return res;
    }
};