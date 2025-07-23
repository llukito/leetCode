class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int n : nums){
            map.put(n, map.getOrDefault(n,0)+1);
        }
        int res = 0;
        for(Integer key : map.keySet()){
            if(map.get(key) == 2){
                res^=key;
            }
        }
        return res;
    }
}