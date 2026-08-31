class Solution {
public:
    long long removeZeros(long long n) {
        long long res = 0;
        int num = 0;
        while(n!=0){
            int rem = n%10;
            n/=10;
            if(rem != 0){
                res = rem*pow(10, num) + res;
                num++;
            }
        }
        return res;
    }
};
