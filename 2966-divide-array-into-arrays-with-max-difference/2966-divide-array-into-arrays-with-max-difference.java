class Solution {
    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        int[][] result = new int[nums.length/3][3];
        int index = 0;
        for(int i=0; i<nums.length; i+=3){
            if(nums[i+2]-nums[i]>k){
                result = new int[0][0];
                return result;
            }
            int[] temp = new int[3];
            temp[0] = nums[i];
            temp[1] = nums[i+1];
            temp[2] = nums[i+2];
            result[index++] = temp;
        }
        return result;
    }
}