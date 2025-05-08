class Solution {
public:
    bool checkPerfectNumber(int num) {
        // // pre computed perfect numbers up to 10^8 which is the constraint
        // unordered_set<int> set = {6, 28, 496, 8128, 33550336};
        // return set.count(num);

        if(num<6)return false; // smallest prime number is 6
        int sum = 1;
        int sqrtNum = sqrt(num);
        for(int i=2; i<=sqrtNum; i++){
            if(num%i == 0){
                sum+=i;
                if(i != num/i) sum+= num/i;
            }
        }
        return sum == num;
    }
};