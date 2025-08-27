class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int cur = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]);
            ans = max(ans, cur);
        }
        int cur1 = nums[0];
        int ans1 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cur1 = min(nums[i], cur1 + nums[i]);
            ans1 = min(ans1, cur1);
        }
        return max(abs(ans1), abs(ans));
    }
};