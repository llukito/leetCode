class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size()!=1){
            vector<int> temp(nums.size()-1,0);
            for(int i=0; i<temp.size(); i++){
                temp[i] = (nums[i]+nums[i+1])%10;
            }
            nums = temp;
        }
        return nums[0];
    }
};