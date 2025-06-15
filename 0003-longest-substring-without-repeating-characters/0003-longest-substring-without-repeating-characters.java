class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left = 0;
        int right = 0;
        int size = 0;
        HashSet<Character> set = new HashSet<>();
        while(left<s.length()){
            if(right<s.length() && !set.contains(s.charAt(right))){
                set.add(s.charAt(right));
                size = Math.max(size, set.size());
                right++;
            } else {
                left++;
                right = left;
                set.clear();
            }
        } 
        return size;  
    }
}