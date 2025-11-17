class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.equals(""))return 0;
        int[] arr = new int[300];
        int left = 0; int right = 0; int res = 1;
        while(right < s.length()){
            arr[s.charAt(right)]++;
            while(arr[s.charAt(right)] > 1){
                res = Math.max(res, right-left);
                arr[s.charAt(left)]--;
                left++;
            }
            right++;
        }
        res = Math.max(res, right-left);
        return res;
    }
}