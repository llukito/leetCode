class Solution {
    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);
        int res = 1;
        int start = -1;
        for(int i=0; i<nums.length; i++){
            if(start == -1){
                start = nums[i];
            } else {
                if(nums[i]-start >k){
                    res++;
                    start = nums[i];
                }
            }
        }
        return res;
    }
}