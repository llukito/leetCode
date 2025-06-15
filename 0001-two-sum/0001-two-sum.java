class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int i=0; i<nums.length ; i++){
            map.put(i,nums[i]);
        }
        for(int i = nums.length-1; i>=0; i--){
            int n = nums[i];
            int s = target-n;
            int idx = find(map, s);
            if(idx!=-1){
                if(idx == i)continue;
                return new int[]{i,idx};
            }
        }
        return null;
    }

    private int find(Map<Integer, Integer> map, int val){
        for(Integer n : map.keySet()){
            if(map.get(n)==val){
                return n;
            }
        }
        return -1;
    }
}