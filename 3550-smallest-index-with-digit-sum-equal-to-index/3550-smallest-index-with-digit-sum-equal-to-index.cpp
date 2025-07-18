class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int digits = 0;
            int n = nums[i];
            while(n){
                digits+=n%10;
                n/=10;
            }
            if(digits==i)return i;
        }
        return -1;
    }
};