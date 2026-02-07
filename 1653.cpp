class Solution {
    public int minimumDeletions(String s) {
        int n  = s.length();
        int[] arr = new int[n]; Arrays.fill(arr, -1);
        int curr = 0;
        for(int i = 0; i < n; i++){
            if(s.charAt(i) == 'a'){
                arr[i] = curr;
            } else {
                curr++;
            }
        } 
        int[] dp = new int[n]; Arrays.fill(dp, 0);
        dp[0] = 0;
        for(int i = 1; i < n; i++){
            if(s.charAt(i) == 'a'){
                dp[i] = Math.min(dp[i-1]+1, arr[i]);
            } else {
                dp[i] = dp[i-1];
            }
        } 
        return dp[n-1];
    }
}
