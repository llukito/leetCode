class Solution {
public:
const int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int res = 0;
        check(nums, target, res, INT_MIN, INT_MAX, 0);
        return res;
    }

    void check(vector<int>& nums, int& target, int& res, int max_, int min_, int index){
        if(index == nums.size()){
            if(max_ != INT_MIN && min_ != INT_MAX){
                if(max_ + min_ <= target){
                    res++;
                }
            }
            return;
        }
        check(nums, target, res, max_, min_, index+1);
        check(nums, target, res, max(max_, nums[index]), min(min_, nums[index]), index+1);
    }
};