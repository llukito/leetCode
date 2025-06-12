class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int maxValue = Integer.MIN_VALUE;
        for(int i=0; i<nums.length-1; i++){
            maxValue = Math.max(maxValue, Math.abs(nums[i]-nums[i+1]));
        }
        maxValue = Math.max(maxValue, Math.abs(nums[0]-nums[nums.length-1]));
        return maxValue;
    }
}