class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int res = 0;
        res+=nums[0];
        nums[0] = nums.back();
        sort(nums.begin(), nums.end()-1);
        res+=nums[0];
        res+=nums[1];
        return res;
    }
};
