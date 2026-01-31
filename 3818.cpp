class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int end = INT_MIN;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] >= nums[i+1]){
                end = max(end, i);
            }
        }
        return end == INT_MIN ? 0 : end+1;
    }
};
