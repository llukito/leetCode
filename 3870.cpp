class Solution {
public:
    int countCommas(int n) {
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += helper(i);
        }
        return sum;
    }

    int helper(int n) {
        int digits = 0;
        while(n!=0){
            digits++;
            n/=10;
        }
        if(digits < 4)return 0;
        return 1; // n <= 10^5
    }
};
