class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> soFar(nums.size(), 1);
        for(int i = 0; i<nums.size(); i++){
            int max_ = 0;
            for(int j = i - 1; j>=0; j--){
                if(nums[j] < nums[i]) max_ = max(max_, soFar[j]+1);
            }
            soFar[i] = max(soFar[i], max_);
        }

        return *max_element(soFar.begin(), soFar.end());
    }
};