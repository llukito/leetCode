class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sz = nums.size();
        int res = 0;       
        for(int i=0; i<sz; i++){
            res+= sz%(i+1)==0 ? nums[i]*nums[i] : 0;
        }
        return res;
    }
};