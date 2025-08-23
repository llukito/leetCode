class Solution {
    public int unequalTriplets(int[] nums) {
        int res = 0;
        for(int i=0; i<nums.length-2; i++){
            for(int j=i+1; j<nums.length-1; j++){
                for(int k = j+1; k<nums.length; k++){
                    if(nums[i] != nums[j] && nums[j]!=nums[k] && nums[i]!=nums[k])res++;
                }
            }
        }
        return res;
    }
}