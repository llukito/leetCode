class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int curr = INT_MIN; int size  = 0; int res = 0; int prev = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > curr){
                size++;
            } else {
                res = max(res, min(prev, size));
                prev = size;
                size = 1;
            }
            curr = nums[i];
            res = max(size/2, res);
        }
        res = max(res, min(prev, size));
        return res;
    }
    
};
