class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=nums.size()-1; i>0; i--){
            for(int j=i-2; j>=0; j--){
                if(nums[i]<nums[i-1]+nums[j]){
                    return nums[i]+nums[i-1]+nums[j];
                } else {
                    break;
                }
            }
        }
        return 0;
    }
};