class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int res = 0;
        int curr = 0;
        for(int n : nums){
            curr+=n;
            if(curr==0)res++;
        }
        return res;
    }
};