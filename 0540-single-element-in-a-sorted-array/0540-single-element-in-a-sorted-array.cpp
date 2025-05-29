class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0; int right = nums.size()-1;
        while(true){
            int index = left + (right-left)/2;
            if(index-1>=0 && nums[index]==nums[index-1]){
                if(index%2==0){
                    right = index-1;
                } else {
                    left = index+1;
                }
            } else if(index+1<nums.size() && nums[index]==nums[index+1]){
                if(index%2==1){
                    right = index-1;
                } else {
                    left = index+1;
                }
            } else {
                return nums[index];
            }
        }
    }
};