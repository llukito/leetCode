class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int changeTwoSmallest = nums[n - 1] - nums[2];
        int changeOneEach = nums[n - 2] - nums[1];
        int changeTwoLargest = nums[n - 3] - nums[0];
        return min(changeTwoSmallest, min(changeOneEach, changeTwoLargest));
    }
};