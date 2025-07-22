class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int res = INT_MIN;
        int curr = 0;
        unordered_set<int> set;
        while(right<nums.size()){
            if(set.count(nums[right])){
                res = max(res, curr);
                curr -= nums[left];
                set.erase(nums[left]);
                left++;
            } else {
                curr+=nums[right];
                set.insert(nums[right]);
                right++;
            }
        }
        res = max(res, curr);
        return res;
    }
};