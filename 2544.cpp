class Solution {
public:
    int alternateDigitSum(int n) {
        int size = to_string(n).size();
        int res = 0;
        int sign = 1;
        while(n!=0){
            int curr = n%10;
            res+=sign*curr;
            sign*=-1;
            n/=10;
        }
        if(size % 2 == 0)return -res;
        return res;
    }
};
