class Solution {
public:
    int countGoodNumbers(long long n) {
        long long evenInd = (n+1)/2;
        long long odd = n - evenInd;
        long long mod = pow(10,9)+7;
        long long five = modPow(5, evenInd, mod);
        long long four = modPow(4, odd, mod);
        return (five*four)%mod;
    }

    long long modPow(long long a, long long n, long long mod){
        if(n==0){
            return 1;
        }
        if(n%2==1){
            n--;
            return (a%mod)*(modPow(a,n,mod)%mod)%mod;
        } else {
            long long half = modPow(a, n/2, mod);
            half%=mod;
            long long res = (half*half)%mod;
            return res;
        }
    }
};