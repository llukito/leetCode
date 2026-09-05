class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> maxs(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                maxs[i] = nums[i];
            } else {
                maxs[i] = max(maxs[i-1], nums[i]);
            }
        }

        vector<int> mins(nums.size(), INT_MAX);
        for(int i = nums.size()-1; i>=0; i--){
            if(i == nums.size()-1){
                mins[i] = nums[i];
            } else {
                mins[i] = min(mins[i+1], nums[i]);
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(maxs[i]-mins[i] <= k){
                return i;
            }
        }
        return -1;
    }
};
