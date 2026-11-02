class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int med = median(nums);
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int n : nums){
            res+=abs(med-n);
        }
        return res;
    }

    int median(auto& nums){
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
