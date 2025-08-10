class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int ones = 0;
        while(n!=0){
            if(n%2==1){
                ones++;
            }
            n/=2;
            if(ones > 1)return false;
        }
        return ones < 2;
    }
};