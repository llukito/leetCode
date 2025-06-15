class Solution {
    public int climbStairs(int n) {
        int f = 1; int s = 2;
        if(n==1)return f;
        if(n==2)return s;
        for(int i=0; i<n-2; i++){
            int temp = s;
            s = s+f;
            f = temp;
        }
        return s;
    }
}