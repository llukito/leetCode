class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int res = -1;
        vector<int> correct = nums;
        sort(correct.begin(), correct.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == correct[i])continue;
            if(res == -1)res = nums[i];
            else res&=nums[i];
        }
        return res == -1 ? 0 : res;
    }
};
