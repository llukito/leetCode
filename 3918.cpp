class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int rev = reverse(n);
        int sum = 0;
        for(int i = min(n, rev); i <= max(n, rev); i++){
            if(prime(i)){
                sum+=i;
            }
        }
        return sum;
    }

    int reverse(int n){
        int rev = 0;
        while(n!=0){
            int rem = n%10;
            n/=10;
            rev*=10;
            rev+=rem;
        }
        return rev;
    }

    bool prime(int n){
        if(n == 1)return false;
        for(int i = 2; i <= sqrt(n); i++){
            if(n%i==0)return false;
        }
        return true;
    }
};
