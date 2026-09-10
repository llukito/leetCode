class Solution {
public:
    bool checkDivisibility(int n) {
        int sumOfDigits = 0;
        int productOfDigits = 1;
        int temp = n;
        while(temp != 0){
            sumOfDigits += temp%10;
            productOfDigits *= temp%10;
            temp/=10;
        }
        return n % (sumOfDigits + productOfDigits) == 0;
    }
};
