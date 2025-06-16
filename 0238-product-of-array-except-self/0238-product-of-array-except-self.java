class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] answer = new int[nums.length];
        ArrayList<Integer> prefix = new ArrayList<>();
        ArrayList<Integer> suffix = new ArrayList<>();
        for(int i=0; i<nums.length; i++){
            if(i==0){
                prefix.add(nums[i]);
            } else {
                prefix.add(prefix.get(prefix.size()-1)*nums[i]);
            }
        }
        for(int i=nums.length-1; i>=0; i--){
            if(i==nums.length-1){
                suffix.add(nums[i]);
            } else {
                suffix.add(suffix.get(suffix.size()-1)*nums[i]);
            }
        }
        Collections.reverse(suffix);
        for(int i=0; i<nums.length; i++){
            int n1 = 1; int n2 = 1;
            if(i-1>=0){
                n1 = prefix.get(i-1);
            }
            if(i+1<suffix.size()){
                n2 = suffix.get(i+1);
            }
            answer[i] = n1*n2;
        }
        return answer;
    }
}