class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0)return false;
        long savedX = x; long newNumber = 0;
        while(x!=0){
            int n = x%10;
            newNumber*=10; 
            newNumber+=n;
            x/=10;
        }
        return savedX == newNumber;
    }
}