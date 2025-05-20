class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int val = 0;
        sort(nums.begin(), nums.end());
        for(int i=nums.size()-1; i>0; i-=2){
            val+= min(nums[i], nums[i-1]);
        }
        return val;
    }
};