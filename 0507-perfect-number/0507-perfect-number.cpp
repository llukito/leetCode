class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1)return false;
        int sum = 1;
        for(int i=2; i<=sqrt(num); i++){
            if(num%i==0){
                sum+=i+num/i;
            }
        }
        return sum == num;
    }
};


// bool checkPerfectNumber(int num) {
//     return num == 6 || num == 28 || num == 496 ||
//             num == 8128 || num == 33550336;
// }