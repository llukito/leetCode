class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int e = 0; int d = 0;
        for(int n : nums){
            e+=n;
            while(n!=0){
                d+=n%10;
                n/=10;
            }
        }
        return abs(e-d);
    }
};