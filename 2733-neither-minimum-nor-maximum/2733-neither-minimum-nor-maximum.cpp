class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max = nums[nums.size()-1];
        int min = nums[0];
        for(int n : nums){
            if(n!=max && n!=min){
                return n;
            }
        }
        return -1;
    }
};