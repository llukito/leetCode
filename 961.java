class Solution {
    public int repeatedNTimes(int[] nums) {
      HashMap<Integer, Integer> mp = new HashMap<>();

        for (int n : nums) {
            mp.put(n, mp.getOrDefault(n, 0) + 1);
            if (mp.get(n) == nums.length / 2) {
                return n;
            }
        }
        return -1;
    }
}