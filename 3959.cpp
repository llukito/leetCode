class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0;
        int squareSum = 0;
        while(n!=0){
            int curr = n%10;
            n/=10;
            digitSum+=curr;
            squareSum+=curr*curr;
        }
        return squareSum - digitSum >= 50;
    }
};
