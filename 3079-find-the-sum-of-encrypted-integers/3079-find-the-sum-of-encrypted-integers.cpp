class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int res = 0;
        for(int n : nums){
            res+=encrypt(n);
        }
        return res;
    }

    int encrypt(int n){
        int maxDigit = 0;
        int size = 0;
        while(n!=0){
            maxDigit = max(maxDigit, n%10);
            n/=10;
            size++;
        }
        int res = 0;
        return maxDigit*((pow(10, size)-1)/9);
    }
};