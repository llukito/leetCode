class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        summ(nums, target, 0, 0, total);
        return total;
    }

    void summ(vector<int>& nums, int target, int sum, int ind, int& total){
        if(ind==nums.size()){
            if(target==sum){
                total++;
            }
            return;
        }
        summ(nums, target, sum-nums[ind], ind+1, total);
        summ(nums, target, sum+nums[ind], ind+1, total);
    }
};