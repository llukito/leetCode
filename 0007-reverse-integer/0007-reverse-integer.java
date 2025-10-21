class Solution {
    public int reverse(int x) {
        if( x == Integer.MIN_VALUE)return 0;
        int sign = 1;
        if(x < 0){
            sign = -1;
            x*=-1;
        }
        double newNumber = 0;
        while(x!=0){
            int n = x%10;
            newNumber*=10; 
            newNumber+=n;
            x/=10;
        }
        if(newNumber >  Integer.MAX_VALUE)return 0;
        newNumber*=sign;
        return (int)newNumber;
    }
}