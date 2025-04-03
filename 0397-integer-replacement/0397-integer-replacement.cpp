class Solution {
public:
    int integerReplacement(int n) {
        return calculate(n,0);
    }

    long long calculate(long long n, int moves){
        if(n==1){
            return moves;
        }
        if(n%2==0){
            return calculate(n/2, moves+1);
        } else {
            long long num1 = calculate(n+1, moves+1);
            long long num2 = calculate(n-1, moves+1);
            return min(num1,num2);
        }
    }
};